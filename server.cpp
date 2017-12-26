#include <netinet/in.h>    // for sockaddr_in
#include <sys/types.h>    // for socket
#include <sys/socket.h>    // for socket
#include <stdio.h>        // for printf
#include <stdlib.h>        // for exit
#include <string.h>        // for bzero
#include <arpa/inet.h>
#include <unistd.h>  //close
#include <iostream>
#include "login.h"
using namespace std;


#define BUFFSIZE 500
#define PORT 8001


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
	server.sin_addr.s_addr = htonl(INADDR_ANY);  //备用
    server.sin_port = htons(PORT);  //绑定端口
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
		
    /* fifth step 接受请求 */
	int sin_size = sizeof(struct sockaddr_in);
	connect_fd = accept(server_fd, (struct sockaddr *)NULL, NULL);
    if(connect_fd == -1){
        perror("接受请求失败 \n");
        exit(1);
    }
	   
    /*---------------------show client---------------*/
    printf("连接成功 \n");

	/*----------------------login and sign up ------*/
		
	
    /*----------------------read and write----------*/
	   
	char seg[] = ",";
	char unuse_char[50];
	while(1){
		bzero(recbuf,sizeof(recbuf));
		rec_n = recv(connect_fd, recbuf, BUFFSIZE, 0);
		recbuf[rec_n] = '\0';
		if((memcmp("bye",recbuf,3))== 0){  //比较前3位是否为bye，决定是否关闭connect
			printf("再见，之后关闭连接 \n");
			break;
		}
		printf("收到消息： %s\n", recbuf);
		
		bzero(wrbuf,sizeof(wrbuf));
		if((memcmp("login", recbuf, 5)) == 0){
			int i = 0;
			char* substr = strtok(recbuf, seg);
			while(substr != NULL){
				if(i == 0)
					strcpy(unuse_char, substr);
				if(i == 1){
					strcpy(users[user_num].name, substr);
					printf("user-name: %s\n", users[user_num].name);
				}
				if(i == 2){
					strcpy(users[user_num].password, substr);
					printf("user-pass: %s\n", users[user_num].password);
				}
				i++;
				substr = strtok(NULL, seg);
			}
			if(login(users[user_num].name, users[user_num].password) == -1){  //login函数  用户名 密码正确返回0  密码错误返回-1  用户名不存在返回-2
			
 				strcpy(wrbuf, "password_error");
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
			else if(login(users[user_num].name, users[user_num].password) == -2){
				strcpy(wrbuf, "user_not_exist");
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
			else{
				strcpy(wrbuf, "ok");
				write(connect_fd, wrbuf, sizeof(wrbuf));
			}
		}
		
		//printf("请输入回复信息： \n");
		//cin.getline(wrbuf, BUFFSIZE);  //todo here
		//printf("键入信息为： %s\n", wrbuf);
		//write(connect_fd,wrbuf,sizeof(wrbuf));
    }

    /*----------------------close-------------------*/
    close(connect_fd);
    close(server_fd);

    return 0;
}