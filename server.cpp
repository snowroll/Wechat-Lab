#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <stdio.h>        // for printf
#include <stdlib.h>        // for exit
#include <string.h>        // for bzero
#include <arpa/inet.h>
#include <unistd.h>  //close
#include <cstdio>
#include <pthread.h>  //多线程
#include <iostream>
#include "login.h"
#include "Dict.h"
using namespace std;


#define BUFFSIZE 500
#define PORT 8001


Dict dict;
void *run(void *arg);  //thread execute function
	
int main(){
	user users[100];
	int user_num = 0;  //用户数量
	int server_fd, connect_fd;
	struct sockaddr_in server;  //服务器地址
	char recbuf[BUFFSIZE];   
	char wrbuf[BUFFSIZE];
	int rec_n;
	
    /* first step 构造监听 socket */
	server_fd = socket(AF_INET, SOCK_STREAM, 0);  //构造socket 服务器套接字
    if(server_fd == -1){  //配置socket
        perror("创建socket失败\n");
        exit(-1);
    }

    /* second step 配置监听地址和端口 */
	
    bzero(&server,sizeof(server));  //绑定套接字到一个ip地址和一个端口上（bind()）
    server.sin_family = AF_INET;  //地址族
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(PORT); 
    //server.sin_addr.s_addr = inet_addr(127.0.0.1);  //服务器ip
	
	
	/* third step 绑定socket */
	int res = bind(server_fd, (struct sockaddr *)&server, sizeof(struct sockaddr));
    if(res == -1){
        perror("绑定失败 \n");
        exit(-1);
    }
	else{
		perror("绑定成功 \n");
	}
	
    /* fourth step 监听 -- 监听队列长度为10 */
    if (listen(server_fd, 10)== -1){  //套接字设为监听模式等待连接请求
        perror("监听失败 \n");
        exit(-1);
    }

	printf("***********     等待客户端发送请求     *********** \n");
	unsigned client_port = 0;  //客户端端口
	char client_ip[20];
	pthread_t tid;  //多线程
	   
    /*---------------------show client---------------*/
    printf("连接成功 \n");

	
    /*----------------------read and write----------*/
	   
	while(1){
		connect_fd = accept(server_fd, (struct sockaddr *)NULL, NULL);
		if(connect_fd == -1){
			perror("接受请求失败 \n");
			exit(1);
		}
		
		pthread_create(&tid, NULL, run, (void *)&connect_fd);
		pthread_detach(tid);
		
    }

    /*----------------------close-------------------*/
    close(server_fd);

    return 0;
}

void *run(void *arg){  //thread execute function
	int connect_fd = *((int*)arg);
	int rec_n = 0;
	char recbuf[BUFFSIZE];   
	char wrbuf[BUFFSIZE]; 
	char seg[] = ",";  //分割符
	char unuse_char[50];  //无用符号
	while(1){
		
		bzero(recbuf,sizeof(recbuf));
		rec_n = recv(connect_fd, recbuf, BUFFSIZE, 0);
		recbuf[rec_n] = '\0';
		printf("收到消息： %s\n", recbuf);
		
		/*    关闭连接    */
		if((memcmp("bye",recbuf,3))== 0){  //比较前3位是否为bye，决定是否关闭connect
			printf("再见，之后关闭连接 \n");
			break;
		}
		
		/*    登录处理    */
		bzero(wrbuf,sizeof(wrbuf));
		if((memcmp("login", recbuf, 5)) == 0){
			int i = 0;
			char* substr = strtok(recbuf, seg);
			while(substr != NULL){
				if(i == 0)
					strcpy(unuse_char, substr);
				if(i == 1){
					strcpy(users.name, substr);
				}
				if(i == 2){
					strcpy(users.password, substr);
				}
				i++;
				substr = strtok(NULL, seg);
			}
			if(login(users.name, users.password) == -1){  //login函数  用户名 密码正确返回0  密码错误返回-1  用户名不存在返回-2
			
 				strcpy(wrbuf, "password_error");
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
			else if(login(users.name, users.password) == -2){
				strcpy(wrbuf, "user_not_exist");
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
			else{
				strcpy(wrbuf, "ok");
				dict.update(users.name, connect_fd);
				dict.show();
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
		}
		
		/*    注册处理    */
		if((memcmp("register", recbuf, 8)) == 0){
			int i = 0;
			char* substr = strtok(recbuf, seg);
			while(substr != NULL){
				if(i == 0)
					strcpy(unuse_char, substr);
				if(i == 1){
					strcpy(users.name, substr);
				}
				if(i == 2){
					strcpy(users.password, substr);
				}
				i++;
				substr = strtok(NULL, seg);
			}
			if(regist(users.name, users.password) == -1){  //register函数  失败返回 -1  成功返回0
 				strcpy(wrbuf, "user_existed");
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
			else{
				strcpy(wrbuf, "success");
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
		}
		
		/*    刷新列表    */
		if((memcmp("update", recbuf, 6)) == 0){
			strcpy(wrbuf, "update,");
			int num = 7;
			for(int i = 0; i < dict.length(); i++){
				for(int j = 0; j < strlen(dict.names[i]); j++){
					wrbuf[num] = dict.names[i][j];
					num++;
				}
				wrbuf[num] = ',';
				num++;
			}
			wrbuf[--num] = '\0';
			write(connect_fd, wrbuf, sizeof(wrbuf));
		}
		
		/*    关闭连接    */
		if(rec_n == 0){
			cout << "client disconnected." << endl;
			close(connect_fd);
			break;
		}
		//len = write(client_fd, buf, len);  //echo to client
	}
	return NULL;
}
