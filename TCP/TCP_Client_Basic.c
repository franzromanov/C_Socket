#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(){
int port;
char ip[12];
//ask
printf("IP ADDRESS: ");
scanf("%s",ip);
printf("PORT: ");
scanf("%d",&port);

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
  char voice[13];
  recv(net_sock,voice,sizeof(voice),0);
  printf("[SERVER]:%13s\n",voice);
}
//esc
 close(net_sock);
 return 0;
}
