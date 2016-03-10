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
char name[10];
char pwd[10];
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
	
	
	pthread_t pid;
	pthread_create(&pid,0,recv_thread,0);

	char c;
	printf("已有账户？(Y/N)");
	scanf("%c",&c);
	if(c=='y'||c=='Y'){
		char msg[100]={0};
		printf("请输入账户名:");
		scanf("%s",name);
		printf("请输入密码:");
		scanf("%s",pwd);
		sprintf(msg,"login %s %s",name,pwd);
		printf("%s\n",msg );
		send(socket_send,msg,strlen(msg),0);

	}		
	 while(1){
	    char msg[10]={0};
        gets(msg);
        if(strcmp(msg,"quit")==0){
        close(socket_send);
        return 0;
        }
       	//printf("%s\n",msg );
     	send(socket_send,msg,strlen(msg),0);//发给服务器
    	
    }
	close(socket_send);
	return 0;

}