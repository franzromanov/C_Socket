#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const* argv[]){
//create_socket
 int net_sock;
 net_sock=socket(AF_INET,SOCK_STREAM,0);

//pass_addr
 struct sockaddr_in net_addr;
 net_addr.sin_family=AF_INET;
 net_addr.sin_port=htons(1234);
 inet_aton("192.168.1.8",&net_addr.sin_addr);

//connect
 if(connect(net_sock,(struct sockaddr*)&net_addr,sizeof(net_addr))<0)printf("\n\e[0;31m[!] \e[0;34mconnection error :: server not exist \e[0;31m[!]\n\n");
 else{
//response
  char voice[1024];
  recv(net_sock,voice,sizeof(voice),0);
  printf("[SERVER]:%1024s\n",voice);
}
//esc
 close(net_sock);
 return 0;
}
