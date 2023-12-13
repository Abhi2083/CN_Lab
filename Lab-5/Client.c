// Client code

#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	//socket api
	int sockfd = socket(AF_INET, SOCK_STREAM,0);
	if(sockfd == -1)
	{
		printf("Error in socket creation\n");
		return 0;
	}
	
	//connect API
	struct sockaddr_in recv_sock;
	recv_sock.sin_family = AF_INET;
	recv_sock.sin_port = 4150;
	recv_sock.sin_addr.s_addr = INADDR_ANY;
	
	int ret_con = connect(sockfd, (const struct sockaddr*)&recv_sock, sizeof(recv_sock));
	if(ret_con == -1)
	{
		printf("Error in connect\n");
		return 0;
	}
	
	char recv_buff[100];
	struct sockaddr_in src_addr;
	int len = sizeof(src_addr);
	
	int k =3;
	while(k>=0)
	{
	k--;
	char send_str[100]; printf("<--- ");
	scanf("%s",send_str);
	//send api	
	int ret_send = send(sockfd, send_str, strlen(send_str), 0);	
	if(ret_send == -1)
	{
		printf("Error in sending to\n");
		return 0;
	}
	
	char recv_buff[100];
	struct sockaddr_in src_addr;
	int len = sizeof(src_addr);
	
	//recv api
	int ret_recv = recv(sockfd, recv_buff, sizeof(recv_buff), 0);
	if(ret_recv == -1)
	{
		printf("Error in recieving from\n");
		return 0;
	}
	printf("---> %s\n",recv_buff);
	
	if(recv_buff == "bye")
	break;
	}
	
	close(sockfd);
	return 0;
}
