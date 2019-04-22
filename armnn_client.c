#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_LEN 3072
//#define PORT 8080
#define IMG_DATA {158,112,49,159,111,47,165,116,51,166,118,53,160,112,46,156,109,41,162,115,47,159,113,45,158,111,44,159,113,41,161,116,41,160,111,52,161,111,49,166,117,41,169,117,45,170,119,44,167,117,40,162,113,38,160,111,39,160,112,43,156,109,44,149,107,45,150,107,45,148,106,43,149,107,44,143,101,39,140,98,43,141,97,41,143,97,38,137,95,36,126,91,36,116,85,33,152,112,51,151,110,40,159,114,45,166,116,56,162,112,49,160,113,43,164,117,47,162,114,45,163,116,46,156,110,38,155,111,41,159,110,54,163,113,52,170,119,41,171,117,40,171,115,33,169,115,30,160,111,33,154,112,41,151,115,50,145,110,53,139,104,55,140,102,52,141,100,48,149,105,50,147,102,46,145,102,45,142,97,38,143,98,34,136,95,31,125,91,32,119,88,34,151,110,47,151,109,33,158,111,36,167,111,48,160,106,42,163,115,44,165,117,45,165,117,45,163,115,43,162,115,43,158,114,48,157,109,57,161,111,51,166,115,38,167,114,37,169,113,35,170,116,39,159,114,47,145,111,54,121,96,49,110,90,52,98,78,50,101,77,47,114,85,50,120,86,48,134,96,55,143,103,51,140,99,39,142,99,35,139,98,34,130,95,34,120,89,33,155,107,40,155,110,32,160,109,31,174,112,44,167,110,43,167,117,46,169,120,48,169,119,48,165,115,44,165,117,45,167,123,57,191,146,95,177,130,75,157,111,41,162,115,47,164,114,54,158,112,58,149,111,67,104,80,47,103,87,65,98,90,76,92,90,84,80,75,66,74,63,50,86,70,52,83,62,39,113,85,45,132,98,46,140,102,43,140,101,39,136,99,39,127,94,36,155,107,41,156,114,48,161,115,49,170,114,47,169,114,43,163,113,40,169,120,47,166,116,44,164,113,41,164,116,42,173,128,59,246,214,164,195,156,107,151,114,56,146,111,60,142,108,71,111,80,50,78,53,31,85,69,56,113,103,98,112,110,111,106,114,118,97,102,105,93,94,93,74,72,67,84,78,70,85,73,47,105,83,45,128,96,48,138,101,46,133,94,36,129,93,36,148,109,54,133,104,64,130,100,57,147,112,53,161,115,44,165,113,39,167,116,41,167,115,41,163,111,37,165,116,39,163,118,42,180,138,85,157,122,78,128,102,58,97,75,43,66,50,31,69,58,43,66,56,45,89,83,76,118,113,110,122,121,120,119,122,122,114,116,116,94,96,96,99,100,97,91,91,86,58,58,47,67,58,37,108,84,49,140,105,58,138,98,44,134,95,40,127,100,57,109,95,80,47,37,17,88,74,28,153,117,48,170,118,43,168,115,40,170,118,43,169,117,42,166,116,37,164,120,39,147,107,52,129,98,59,127,108,75,100,87,70,68,67,57,78,83,72,72,75,64,83,84,74,132,130,121,146,142,132,124,118,108,105,99,90,107,102,94,115,111,103,85,83,77,63,71,69,46,47,39,79,61,36,132,98,58,141,99,48,134,93,39,131,115,90,99,96,92,42,43,38,70,64,41,143,111,56,167,117,42,165,114,36,168,116,39,171,119,49,161,113,51,140,109,51,120,94,49,130,110,77,144,131,107,116,106,93,88,87,79,91,95,88,85,88,82,77,77,69,124,118,107,163,153,140,136,124,112,102,93,81,106,98,88,100,93,84,85,81,74,54,60,58,49,53,49,57,47,32,107,83,50,138,103,51,136,97,39,170,161,144,103,105,105,54,58,59,124,121,113,153,124,82,161,113,43,163,117,41,166,122,50,165,121,66,174,135,95,113,89,59,125,105,78,157,141,121,156,143,128,121,111,101,86,80,74,82,81,77,84,85,82,80,78,73,81,71,61,138,125,112,146,135,123,113,103,93,87,79,70,83,77,69,86,82,76,71,73,67,56,57,53,40,35,27,74,59,35,133,106,59,137,103,45,180,176,163,134,139,143,94,100,105,154,154,149,174,149,112,158,116,51,156,116,47,153,118,60,207,180,146,237,214,198,207,180,166,156,131,119,174,153,145,148,131,125,125,110,107,93,85,79,86,84,79,74,74,71,59,57,53,76,68,58,137,125,112,143,133,122,133,124,114,106,98,89,86,81,74,87,85,78,84,85,78,75,76,71,50,49,43,40,30,15,95,75,44,132,103,57,183,183,175,108,116,122,142,151,158,165,169,168,177,156,122,155,112,50,159,118,51,122,89,47,213,197,179,237,224,226,220,191,188,164,135,131,183,159,155,156,137,132,125,108,104,120,111,104,78,76,69,80,80,77,45,44,40,91,85,77,175,165,154,157,147,137,155,147,138,107,100,92,87,83,77,103,102,96,88,88,79,78,79,73,59,59,59,41,36,33,59,46,31,104,81,46,188,191,189,100,108,116,135,144,153,170,175,178,187,167,136,166,120,59,173,123,55,134,93,44,117,95,80,194,182,188,199,171,164,170,142,133,185,161,151,189,171,159,134,119,106,117,107,95,102,98,89,84,84,79,38,38,34,125,121,113,210,201,192,160,152,142,146,139,130,93,89,82,83,80,75,94,93,88,104,104,94,85,87,81,73,75,78,55,53,55,62,55,48,76,56,26,189,194,194,90,96,105,127,134,144,175,180,185,174,156,133,166,123,68,178,123,53,159,109,47,97,68,44,168,154,152,168,144,126,137,114,94,186,166,148,216,202,183,160,149,129,123,113,98,120,114,105,115,114,109,50,50,47,150,147,140,194,187,178,155,149,140,123,118,111,91,88,83,84,83,79,84,84,80,95,95,85,86,87,81,84,87,89,73,73,73,79,74,64,73,55,24,189,192,193,93,95,103,152,154,163,185,188,192,119,110,98,136,106,66,173,124,58,167,116,50,103,72,39,147,132,120,145,125,103,167,149,127,189,174,155,226,216,200,180,172,157,141,131,117,126,117,107,117,114,109,71,71,68,154,152,147,186,181,174,149,144,136,114,110,104,87,85,80,80,80,76,72,73,70,80,80,72,99,100,94,100,101,99,90,88,81,97,89,69,94,73,34,194,196,196,108,107,112,168,167,172,186,186,188,105,109,109,99,89,67,156,119,62,167,122,55,100,74,34,115,106,88,138,123,103,198,185,169,190,180,169,172,165,159,145,140,140,154,143,134,146,136,125,103,100,95,71,71,70,152,152,149,179,175,170,137,133,127,130,128,122,110,109,105,85,86,83,91,93,91,95,96,90,109,110,104,115,116,111,100,96,80,97,85,53,117,95,47,197,197,197,132,129,136,172,167,174,184,178,181,130,137,142,78,83,77,140,120,88,155,125,77,115,94,52,130,120,93,143,131,116,230,221,211,242,236,230,145,138,137,135,130,130,131,121,112,121,112,101,108,104,95,95,88,75,144,134,118,168,159,146,152,147,138,112,108,101,87,85,80,71,72,68,87,88,87,105,104,99,112,109,99,120,110,93,103,86,54,121,96,48,136,104,48,203,203,204,146,146,160,168,164,178,191,182,188,168,170,172,78,86,90,126,125,126,138,126,113,138,121,82,96,80,37,154,143,133,173,163,155,162,152,141,140,132,117,113,106,88,113,106,90,101,101,92,105,101,87,112,90,58,171,143,104,156,138,109,148,141,126,135,130,118,109,105,97,78,76,72,79,79,77,94,93,94,101,91,82,107,83,55,125,88,45,151,108,55,144,104,46,214,215,215,163,166,180,164,167,184,183,184,194,176,182,186,94,102,105,96,96,102,156,149,145,148,137,111,106,93,61,129,116,105,118,105,95,114,102,89,116,105,89,102,91,73,115,110,98,86,91,88,101,103,95,144,128,102,118,96,64,68,56,32,128,120,105,133,126,115,75,69,61,60,56,51,58,56,53,71,70,65,102,93,78,116,94,64,143,112,68,150,116,64,140,110,54,212,211,205,178,184,192,167,175,189,173,181,193,176,184,188,124,131,133,86,88,96,141,139,143,153,148,141,135,128,111,104,90,80,77,64,55,134,121,108,124,111,96,129,117,100,147,143,133,85,92,93,92,96,93,150,139,120,132,117,93,117,109,92,107,99,86,75,68,58,64,59,52,44,41,39,65,62,60,86,69,40,133,105,59,155,119,62,160,120,54,154,115,45,151,111,46,199,192,180,187,189,187,171,176,181,174,179,185,177,182,184,144,149,152,86,90,99,119,121,132,122,124,130,137,136,135,144,134,126,70,59,51,129,118,108,108,97,86,145,134,123,184,176,168,116,118,118,73,75,73,131,119,103,137,124,105,134,129,118,89,86,78,51,49,44,52,51,50,47,49,52,90,90,93,121,91,60,163,118,68,171,121,64,164,113,52,158,111,50,149,107,46,165,156,146,195,193,187,179,178,175,177,173,172,181,181,180,152,157,160,99,103,111,131,135,146,171,175,185,103,105,111,93,90,87,80,77,73,93,90,86,122,118,116,178,173,173,191,182,177,150,148,148,100,100,101,89,78,66,87,77,63,60,61,57,46,52,54,38,46,51,24,33,41,46,57,69,60,71,83,108,100,75,144,125,82,144,123,76,128,109,61,127,113,69,120,105,63,117,120,124,195,200,200,177,178,176,178,169,168,181,179,179,138,144,147,83,87,91,150,153,159,245,247,250,219,222,225,133,140,144,134,141,147,149,156,164,176,182,192,190,196,208,194,192,197,168,172,181,125,133,143,110,109,109,61,62,62,35,49,58,34,54,68,49,70,87,58,81,102,61,85,110,58,84,111,69,99,122,72,101,119,78,104,120,69,96,112,59,92,112,55,90,115,79,105,133,175,197,213,174,183,192,176,172,177,177,177,182,140,146,150,109,112,113,211,211,209,253,252,247,252,253,252,208,224,232,124,143,157,114,132,149,124,141,162,116,133,156,122,133,152,104,124,148,68,93,119,68,87,104,60,82,101,52,84,111,50,84,110,51,85,115,56,93,125,56,94,131,51,91,130,43,96,135,51,104,141,59,108,142,48,97,132,43,97,137,42,95,132,41,89,135,96,137,168,144,168,188,168,174,188,178,182,192,165,170,174,165,166,164,246,245,237,253,251,241,227,231,228,110,136,153,60,88,111,53,80,105,49,76,105,49,75,107,48,72,101,45,79,115,42,81,120,46,81,113,42,82,116,38,86,125,46,90,125,46,89,126,43,87,128,42,89,132,46,93,139,46,94,137,50,96,137,55,96,135,53,94,134,51,95,139,45,90,133,29,91,141,29,87,130,59,102,134,131,153,176,166,179,191,132,136,137,194,189,181,254,250,242,241,245,245,141,159,175,61,94,127,50,84,118,50,84,119,51,85,121,49,83,120,50,84,116,47,86,117,42,84,117,39,82,115,34,79,113,35,83,120,39,86,125,38,85,125,42,89,130,45,92,134,56,103,145,62,103,142,59,101,142,56,102,146,50,99,144,46,94,140,51,103,149,48,111,162,30,94,140,34,85,124,73,106,136,128,148,167,128,136,143,215,213,209,255,253,249,187,198,205,66,93,118,54,91,128,50,88,125,52,90,127,52,90,127,46,83,121,45,82,115,43,82,113,41,81,112,36,80,113,39,83,117,40,86,123,40,89,131,43,92,134,46,95,138,59,108,150,62,110,152,64,109,147,59,108,149,54,108,154,50,105,152,70,123,167,83,137,182,52,114,165,35,99,147,31,86,130,41,83,122,66,95,126,128,145,164,224,229,234,240,245,247,124,143,153,58,92,114,49,87,123,56,94,131,54,92,129,44,82,119,44,82,119,47,83,119,46,84,119,43,83,119,43,86,123,44,88,127,44,90,131,45,97,141,54,106,150,58,110,154,54,105,150,46,97,141,43,95,140,36,91,138,51,108,158,73,130,178,85,138,182,76,125,169,50,110,162,35,98,149,29,89,138,35,86,133,44,83,126,78,106,138,202,219,233,211,228,234,97,126,140,65,104,126,54,94,129,48,87,124,58,97,133,48,87,123,40,80,116,45,82,119,47,84,122,48,87,126,47,89,130,46,89,132,51,97,140,39,92,138,39,93,139,48,102,148,47,101,147,39,93,139,28,85,133,40,101,153,67,129,182,67,126,176,46,98,142,51,96,139,50,108,161,35,97,147,32,92,143,33,88,141,41,88,138,46,84,125,104,133,159,170,197,211,64,100,119,54,97,121,52,94,128,53,95,130,61,103,139,58,100,135,54,96,131,45,83,120,42,79,118,41,80,120,46,88,130,49,92,135,46,92,136,42,95,139,40,93,138,39,92,136,37,90,135,40,93,138,44,102,151,63,125,178,47,110,164,31,90,140,15,60,103,51,93,136,68,124,177,42,100,148,31,88,137,38,91,146,37,87,139,43,89,132,42,79,113,71,107,133,49,89,114,31,77,105,27,71,105,38,82,117,49,93,128,56,100,135,58,102,137,53,92,128,56,94,131,60,99,137,57,99,139,53,97,138,50,95,137,45,94,136,39,88,131,33,83,125,42,91,133,62,112,154,79,132,179,73,131,181,56,116,168,38,97,146,13,64,108,40,85,127,61,116,168,49,102,148,35,85,132,43,91,143,39,90,139,42,92,134,44,88,125,40,81,112,42,85,115,27,72,104,23,67,102,30,74,109,27,71,106,29,73,108,36,80,115,47,86,120,56,95,128,62,101,135,66,109,144,75,119,156,69,113,152,49,95,134,43,88,127,43,88,127,60,105,144,85,130,170,109,156,197,93,145,190,60,115,164,26,82,130,29,82,126,20,64,107,54,107,160,56,105,149,45,89,132,43,86,134,40,89,134,40,92,132,40,87,123,38,81,115,36,79,114,26,69,105,22,66,101,29,73,108,25,69,104,29,73,108,19,63,98,18,58,89,32,70,100,47,87,118,61,104,137,74,119,152,66,111,145,53,96,131,52,95,130,45,87,123,67,109,145,89,131,167,105,146,182,89,135,175,48,99,145,24,77,124,34,84,129,21,67,110}

static inline uint64_t
ps_tsc(void)
{
	unsigned long a, d, c;

	__asm__ __volatile__("rdtsc" : "=a" (a), "=d" (d), "=c" (c) : : );

	return ((uint64_t)d << 32) | (uint64_t)a;
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void func(int sockfd, int num)
{
   char buff[MAX_LEN];
   unsigned long latency[num];
   unsigned long overall = 0;
   unsigned long long start, end;
   int i = 0;
   uint8_t img_data[3*32*32] = IMG_DATA;
   for (i = 0; i < num; i++) {
       bzero(buff, sizeof(buff));
       start = ps_tsc();
       write(sockfd, img_data, 3072);
       bzero(buff, sizeof(buff));
       read(sockfd, buff, sizeof(buff));
	   end = ps_tsc();
	   latency[i] = (unsigned long)((end-start)/2400);
	   overall += latency[i];
   }
   qsort(latency, num, sizeof(unsigned long), compare);
   printf("result:%srequest num: %d\n", buff, num);
   printf("99%% latency: %ld us, overall latency: %ldus\n", latency[(int)(num*0.99)], overall);
}

int main(int argc, char** argv)
{
   int sockfd, connfd;
   struct sockaddr_in servaddr, client_socket;    // socket create and varification
   unsigned long long start, end;
   unsigned long long latency;

   start = ps_tsc();
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   char* server_ip = argv[1];
   int server_port = atoi(argv[2]);
   int client_port = atoi(argv[3]);
   int num = atoi(argv[4]);
   if (sockfd == -1) {
       exit(0);
   }
   bzero(&servaddr, sizeof(servaddr));    // assign IP, PORT
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = inet_addr(server_ip);
   servaddr.sin_port = htons(server_port);    // connect the client socket to server socket

   client_socket.sin_family = AF_INET;
   client_socket.sin_addr.s_addr = htons(INADDR_ANY);
   client_socket.sin_port = htons(client_port);

   int err_log =bind(sockfd, (struct sockaddr*)&client_socket, sizeof(client_socket));
   if (err_log != 0) {
       perror("binding");
	   close(sockfd);
	   exit(-1);
   }
   if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
       exit(0);
   }
   func(sockfd, num);    // close the socket
   close(sockfd);
   end = ps_tsc();
   latency = end - start;
   printf("overall latency: %ldus\n", (unsigned long)(latency/2400));
}
