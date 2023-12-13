// Server code

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
	
	//bind API
	struct sockaddr_in recv_sock;
	recv_sock.sin_family = AF_INET;
	recv_sock.sin_port = htons(3207);
	recv_sock.sin_addr.s_addr = INADDR_ANY;
	
	int ret_bind = bind(sockfd, (const struct sockaddr*)&recv_sock, sizeof(recv_sock));
	if(ret_bind == -1)
	{
		printf("Error in binding the socket\n");
		return 0;
	}
	
	//listen API
	int ret_lis = listen(sockfd,5);
	if(ret_lis == -1)
	{
		printf("Error in listen\n");
		return 0;
	}
	
	//accept API
	int len_recv_sock=sizeof(recv_sock);
	int datafd = accept(sockfd, (struct sockaddr*)&recv_sock, &len_recv_sock);
	if(datafd == -1)
	{
		printf("Error in accept\n");
		return 0;
	}
	
	//create ls file
	int ret_sys = system("ls>res_S.txt");
	if(ret_sys == -1)
	{
		printf("Error in system");
		return 0;
	}
	
	FILE* file;
	file = fopen("res_S.txt","r");
	
	while(!feof(file))
	{
		char file_buff[100];
		fread(file_buff, sizeof(char), 10, file);
		int ret_send = send(datafd, file_buff, strlen(file_buff), 0);
		printf("%s",file_buff);
	}		
	
	close(datafd);
	return 0;
}
