/*
 ============================================================================
 Name        : NN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

unsigned long buf[65536];
//extern int cifar10(unsigned long buf_addr);
extern int input(uint8_t *data_set, int len, unsigned long buf_addr);
#define DATA_SET_LEN 3072

int main(void) {

	unsigned short port = 8080;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
	    exit(-1);
	}

	struct sockaddr_in my_addr;
	bzero(&my_addr, sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port   = htons(port);

	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int err_log = bind(sockfd, (struct sockaddr*)&my_addr, sizeof(my_addr));
	if( err_log != 0)
	{
	    perror("binding");
	    close(sockfd);
	    exit(-1);
	}

	err_log = listen(sockfd, 10);
	if(err_log != 0)
	{
	    perror("listen");
	    close(sockfd);
	    exit(-1);
	}

	while(1)
	{

	    char cli_ip[INET_ADDRSTRLEN] = {0};
	    struct sockaddr_in client_addr;
	    socklen_t cliaddr_len = sizeof(client_addr);

	    int connfd = accept(sockfd, (struct sockaddr*)&client_addr, &cliaddr_len);
	    if(connfd < 0)
	    {
	        perror("accept");
	        close(sockfd);
            exit(-1);
	    }

	    pid_t pid = fork();
	    if(pid < 0){
	    	perror("fork");
	        _exit(-1);
	    }else if(0 == pid){
	    	//close(stdin);
	    	//close(stdout);
	    	//close(stderr);
	    	close(sockfd);

	    	char output_buf[10] = {0};
	        char recv_buf[1024] = {0};
	        int recv_len = 0;
	        int output = 0;
	        int curr_recv_len = 0;
	        uint8_t image_data[3072];

	        memset(cli_ip, 0, sizeof(cli_ip));
	        inet_ntop(AF_INET, &client_addr.sin_addr, cli_ip, INET_ADDRSTRLEN);
	        //printf("client ip=%s,port=%d\n", cli_ip,ntohs(client_addr.sin_port));

	        while (1) {
	        	while (curr_recv_len < DATA_SET_LEN){
	        	    recv_len = recv(connfd, recv_buf, sizeof(recv_buf), 0);
	        	    memcpy(image_data + curr_recv_len, recv_buf, recv_len);
	        	    curr_recv_len += recv_len;
	            }
	            output = input(image_data, DATA_SET_LEN, (unsigned long)buf);
	            snprintf(output_buf, sizeof(output_buf), "%d\n\n", output);
	      	    send(connfd, output_buf, sizeof(output_buf), 0);
	      	}
	        close(connfd);
	        exit(0);

	    }
	    else if(pid > 0){
	        close(connfd);
	    }
	}
	return EXIT_SUCCESS;
}
