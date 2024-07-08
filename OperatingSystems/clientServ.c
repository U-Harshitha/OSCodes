#include<unistd.h>
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#define MAX 80
#define PORT 32099
#define SA struct sockaddr
void func(int sockfd)
{
char buff[MAX];
int n;
for(;;)
{
bzero(buff,MAX);
read(sockfd,buff,sizeof(buff));
printf("from client: %s\t to client:",buff);
bzero(buff,MAX);
n=0;
while((buff[n++]=getchar())!='\n');
write(sockfd,buff,sizeof(buff));
if(strncmp("exit",buff,4)==0)
{
printf("server exit...\n");
break;
}
}
}
int main()
{
int sockfd,connfd,len;
struct sockaddr_in servaddr,cli;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("socket successfully created...\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);
if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0)
{
printf("socket bind failed...\n");
exit(0);
}
else
printf("socket successfully binded...\n");
if((listen(sockfd,5))!=0)
{
printf("listen failed...\n");
exit(0);
}
else
printf("server listening...\n");
len=sizeof(cli);
connfd=accept(sockfd,(SA*)&cli,&len);
if(connfd<0)
{
printf("server accept failed...\n");
exit(0);
}
else
printf("server accept the client...\n");
func(connfd);
close(sockfd);
}
