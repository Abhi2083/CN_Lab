#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
int main(){
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd ==-1){
		printf("Error in creation of socket");
		return 0;
	}
	
	struct sockaddr_in recv_sock,send_sock;
	recv_sock.sin_family = AF_INET;
	recv_sock.sin_port=5000;
	recv_sock.sin_addr.s_addr=INADDR_ANY;
	
	
	int ret = bind(sockfd,(const struct sockaddr *)&recv_sock,sizeof(recv_sock));
	if(ret==-1)
	{
		printf("Error in bind");
		return 0;
	}
	char str[100];
	strcpy(str,"Hola Kiitians");
	int send = sendto(sockfd, str,strlen(str),0,(const struct sockaddr*)&send_sock,sizeof(send_sock));
	
	
	printf("COMPILATION SUCCESSFULL");
	return 0;
}

