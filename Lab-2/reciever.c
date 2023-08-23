// Reciever code

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
	int sockfd = socket(AF_INET, SOCK_DGRAM,0);
	if(sockfd == -1)
	{
		printf("Error in socket creation\n");
		return 0;
	}
	
	struct sockaddr_in recv_sock;
	recv_sock.sin_family = AF_INET;
	recv_sock.sin_port = 4000;
	recv_sock.sin_addr.s_addr = INADDR_ANY;
	
	//bind api
	int ret_bind = bind(sockfd, (const struct sockaddr*)&recv_sock, sizeof(recv_sock));
	if(ret_bind == -1)
	{
		printf("Error in binding the socket\n");
		return 0;
	}
	
	char recv_buff[100];
	struct sockaddr_in src_addr;
	int len = sizeof(src_addr);
	
	while(1)
	{
	//recvfrom api
	int ret_recv = recvfrom(sockfd, recv_buff, sizeof(recv_buff), 0, (struct sockaddr*)&src_addr, &len);
	if(ret_recv == -1)
	{
		printf("Error in recieving from\n");
		return 0;
	}
	
	printf("---> %s\n",recv_buff);
	
	char send_str[100]; printf("<--- ");
	scanf("%s",send_str);
	
	//sendto api
	int ret_send = sendto(sockfd, send_str, strlen(send_str), 0, (const struct sockaddr*)&src_addr, sizeof(src_addr));	
	if(ret_send == -1)
	{
		printf("Error in sending to\n");
		return 0;
	}
	if(recv_buff=="bye")
	break;
	}
	
	close(sockfd);
	return 0;
}
