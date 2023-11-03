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
	recv_sock.sin_port = 4150;
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
	
	while(1){
	//accept API
	int len_recv_sock=sizeof(recv_sock);
	int datafd = accept(sockfd, (struct sockaddr*)&recv_sock, &len_recv_sock);
	if(datafd == -1)
	{
		printf("Error in accept\n");
		return 0;
	}
	
	int ret = fork();
	if(ret == 0){
	close(sockfd);
	
	char recv_buff[100];
	struct sockaddr_in src_addr;
	int len = sizeof(src_addr);
	
	
	//recv API
	int ret_recv = recv(datafd, recv_buff, sizeof(recv_buff), 0);
	if(ret_recv == -1)
	{
		printf("Error in recieving\n");
		return 0;
	}
	
	printf("---> %s\n",recv_buff);
	
	char send_str[100]; printf("<--- ");
	scanf("%s",send_str);
	
	//send API
	int ret_send = send(datafd, send_str, strlen(send_str), 0);	
	if(ret_send == -1)
	{
		printf("Error in sending to\n");
		return 0;
	}
	
	break;
	}
	
	if (ret != 0){
	
	close(datafd);
	}
	}
	return 0;
}
