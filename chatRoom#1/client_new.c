#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#define SOCKET_PORT 8088

int socket_send;
void* recv_thread(void* p){
	while(1){
		int bufsize;
		char buf[100]={0};
		if((bufsize= recv(socket_send,buf,sizeof(buf),0))==-1)
	{
		printf("recv error\n");
		exit(1);
	}
	buf[bufsize]='\0';
	printf("server message: %s\n",buf);
	}
}
int main(int argc ,char *argv[]){
	if(argc !=2){
		printf("error\n");
	}
	
	char name[20];
	strncpy(name, argv[1], 20);
	struct hostent *host;
	struct sockaddr_in server;

	if((socket_send = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		printf("socket() error\n");
		exit(1);
	}
	host = gethostbyname("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(SOCKET_PORT);
	server.sin_addr = *((struct in_addr *)host->h_addr);
	if(connect(socket_send,(struct sockaddr *)&server,sizeof(server))==-1){
		printf("connect() error\n");
		exit(1);
	}
	
	

	if(send(socket_send,name,sizeof(name),0)==-1)
	{
		printf("sned() error\n");
		exit(1);
	}
	pthread_t pid;
	pthread_create(&pid,0,recv_thread,0);
	 while(1){
	    char buf[100] = {0};
        scanf("%s",buf);//接受用户输入
        printf("%s",buf);
        char msg[100] = {0};
		sprintf(msg,"%s说:%s",name,buf);
        send(socket_send,msg,strlen(msg),0);//发给服务器
     }
	close(socket_send);
	return 0;

}