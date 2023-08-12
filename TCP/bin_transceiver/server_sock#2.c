//------------LIBRARY---------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include "./talk/talk.h"
//----------------------------------

//declare
//parts--------------------------[1]

char ip[13]="127.0.0.1";
int port,s_sock;
struct sockaddr_in s_addr;

//----------------------------------

//parts--------------------------[2]

creds usr_main,usr_cmp;
void _load(creds* usr_cmp){
 strcpy(usr_cmp->name,"Neo_Crackers");
 strcpy(usr_cmp->password,"EA_NASIR2812");
}

//----------------------------------

//parts--------------------------[3]
 
FILE *bin,*txt;
int  bin_buff[256];
char txt_buff[256];
 
//----------------------------------



//main
int main(){

//AdminLOGIN_Session------------------------------------------------[A]
 _load(&usr_cmp);
 _MENU();
 _USER_CREDS(&usr_main,usr_cmp);

//---------------------------------------------------------------------



/*
//Network_initiation_Session----------------------------------------[B]

//Create_Socket
 s_sock=socket(AF_INET,SOCK_STREAM,0);
 
 //adressing
 s_addr.sin_family=AF_INET;//get_addrFamilyType
 s_addr.sin_port=htons(port);//get_PortNumber
 inet_aton(ip,&s_addr.sin_addr);//get_IPaddr


//binding
 bind(s_sock,(struct sockaddr*)&s_addr,sizeof(s_addr));

//listen_forConnection
 listen(s_sock,3);

//accepting_connection
 int c_sock=accept(s_sock,,NULL,NULL);

//---------------------------------------------------------------------



//communication_session---------------------------------------------[C]








//---------------------------------------------------------------------




//esc
 close(s_sock);
*/

 return 0;
}
