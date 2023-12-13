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
	recv_sock.sin_port = htons(3207);
	recv_sock.sin_addr.s_addr = INADDR_ANY;
	
	int ret_con = connect(sockfd, (const struct sockaddr*)&recv_sock, sizeof(recv_sock));
	if(ret_con == -1)
	{
		printf("Error in connect\n");
		return 0;
	}
	
	FILE *file;
	file = fopen("res_C.txt","w");
	
	
	while(1)
	{
		char recv_buff[100];
		int ret_recv = recv(sockfd, recv_buff, sizeof(recv_buff), 0);
		if(ret_recv == -1)
		{
			printf("Error in recieving\n");
			return 0;
		}
		fwrite(recv_buff, sizeof(char), 10, file);
		printf("%s",recv_buff);
		if(ret_recv < 10)
			break;
	}
	
	close(sockfd);
	return 0;
}
