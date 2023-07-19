#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>


//main
int main(){
///::START::///
char ip[12];
int port;
//ask
printf("input IP: ");
scanf("%12s",ip);
printf("port: ");
scanf("%d",&port);



//create_socket
 int net_sock=socket(AF_INET,SOCK_STREAM,0);

//sock_addr
 struct sockaddr_in net_addr;
 net_addr.sin_family=AF_INET;
 net_addr.sin_port=htons(port);
 inet_aton(ip,&net_addr.sin_addr);

//bind
 bind(net_sock,(struct sockaddr*)&net_addr,sizeof(net_addr));

//listen
 listen(net_sock,3);

//accept
 int client_sock=accept(net_sock,NULL,NULL);
//send
 char msg[12]="Hello World";
 send(client_sock,msg,sizeof(msg),0);

//esc
 close(net_sock);
 printf("\e[0;31m[!]\e[0;0mclosing\e[0;31m[!]\n");
 return 0;
}

