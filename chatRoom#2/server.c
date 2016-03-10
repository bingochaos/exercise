#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#define SOCKET_PORT 8088

#define MAXRECVLEN 20
char buff[MAXRECVLEN];
struct Client
{
	char name[20];
	char password;
	int socket;
	int online_time_total;
	int login_time;
};
struct Client clients[10]={0};
int client_num=0;
void sendMsgToAll(char *msg){
	for(int i=0;i<client_num;i++){
		printf("send to%d\n", clients[i].socket);
		send(clients[i].socket,msg,strlen(msg),0);
	}
}
void* check(char *order){
	
	   char* orderName =strtok(order," ");
	   printf("orderName:%s\n", orderName); 
	   char* msg = strtok(NULL,"\n");
	   printf("msg:%s\n", msg);
	   if(strcmp(order,"chat")==0){
	   		sendMsgToAll(msg);
	   }

}
void* service_thread(void* p){
		int socket = *(int*)p;
		printf("socket %d\n",socket );
		clients[client_num].socket=socket;
		client_num++;
		char order[20]={0};
		while(1){
			if(recv(socket,order,sizeof(order),0)>0){
			check(order);
		}
		

	// 	while(1){
	// 			if(recv(socket,buff,sizeof(buff),0)<0){	
	// 				printf("receive111 error\n");
	// 				char name[10];
	// 				for(int i=0;i<client_num-1;i++){
	// 					if(clients[i].socket==socket){	
	// 						strcpy(name,clients[i].name);
	// 						clients[i].socket=clients[client_num-1].socket;
	// 						strcpy(clients[i].name,clients[client_num-1].name);
	// 				}
	// 			}
	// 			client_num--;
	// 			printf("%d\n",client_num );
	// 			printf("%d quit\n",socket );
	// 			for(int i=0;i<client_num;i++){
	// 				printf("%s quit\n", clients[i].name);
	// 				send(clients[i].socket,name,strlen(name),0);
	// 			}
	// 			//close(socket);
	// 			return 0;
	// 		}
		
	// 		for(int i=0;i<client_num;i++){
	// 		printf("send to %s\n", clients[i].name);
	// 		send(clients[i].socket,buff,strlen(buff),0);
	// 		}
		
	// }
	}

}


int main(int argc,char *argv[]){
	int listened_socket,sendsocket;
	struct sockaddr_in server;
	struct sockaddr_in client;
	socklen_t addrlen;

	if((listened_socket = socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		printf("socket() error\n" );
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(SOCKET_PORT);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(listened_socket,(struct sockaddr *)&server,sizeof(server))== -1)
	{
		printf("bind() error\n" );
		exit(1);
	}

	if(listen(listened_socket,2)==-1){
		printf("listen() error\n");
		exit(1);
	}

		while(1){

			addrlen = sizeof(client);

		if((sendsocket = accept(listened_socket,(struct sockaddr *)&client,&addrlen))==-1){
			printf("accept() error\n");
			exit(1);
		}
		pthread_t pid;
		pthread_create(&pid,0,service_thread,&sendsocket);

	}
	close(listened_socket);
	return 0;


}
