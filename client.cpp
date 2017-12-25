#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include<arpa/inet.h>  //inet_pton
#include <errno.h>
#include <unistd.h>  //close

#define BUFFSIZE 50

int main(int argc, char** argv){
    int sock_fd;
    char recbuf[BUFFSIZE], wrbuf[BUFFSIZE];
    int rec_len;
    struct sockaddr_in server;
	
	if( argc != 2){
    	printf("usage: ./client <ipaddress>\n");
    	exit(1);
    }

    /*---------------------socket---------------------*/
    if((sock_fd = socket(AF_INET,SOCK_STREAM,0))== -1){
        perror("socket error\n");
        exit(1);
    }

    /*---------------------connect--------------------*/
    bzero(&server,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8002);
    inet_pton(AF_INET, argv[1],&server.sin_addr);
    if(connect(sock_fd,(struct sockaddr *)&server,sizeof(server))== -1){
        perror("connect() error\n");
        exit(1);
    }

    /*-----------------------read and write------------------*/
    while(1){
		bzero(wrbuf,sizeof(wrbuf));
		bzero(recbuf,sizeof(recbuf));    
		printf("Please input the info:\n");
		scanf("%s",wrbuf);
		printf("success send\n");
		/*if((memcmp("bye",wrbuf,3))== 0){
			write(sock_fd,wrbuf,strlen(wrbuf));
			printf("Bye-bye then close the connect...\n");
			break;
		}*/
		printf("%s\n",wrbuf);
		write(sock_fd,wrbuf,strlen(wrbuf));
		printf("已发送 \n");
		//rec_len = read(sock_fd,recbuf,sizeof(recbuf));
		//recbuf[rec_len] = '\0';
		//printf("The info from server is: %s\n",recbuf);
    }
    /*------------------------close--------------------------*/
    close(sock_fd);

    return 0;
}
