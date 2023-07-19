#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

//main
int main(){
int port;
char ip[12];
char fly [9];//password
//ask
printf("IP ADDRESS: ");
scanf("%s",ip);
printf("PORT: ");
scanf("%d",&port);
printf("password: ");
scanf("%9s",fly);

//create_socket
 int net_sock;
 net_sock=socket(AF_INET,SOCK_STREAM,0);

//pass_addr
 struct sockaddr_in net_addr;
 net_addr.sin_family=AF_INET;
 net_addr.sin_port=htons(port);
 inet_aton(ip,&net_addr.sin_addr);

//connect
 if(connect(net_sock,(struct sockaddr*)&net_addr,sizeof(net_addr))==-1)printf("\n\e[0;31m[!] \e[0;34mconnection error :: server not exist \e[0;31m[!]\n\n");
 else{
//response
  char land[13];

  send(net_sock,fly,sizeof(fly),0);
  recv(net_sock,land,sizeof(land),0);
  printf("[server]::%s\n",land);
}
//esc
 close(net_sock);
 return 0;
}
