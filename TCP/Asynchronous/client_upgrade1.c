//---------LIBRARIES-----------*
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
//-----------------------------*

/*
//////how_to_establish_a_communication////
-create_socket
-bind_socket
-connect_to_server
-Communicate[send/recieve]
-CommunicationEnded[CLOSE]
//////////////////////////////////////////
*/



//declare_variables

//part-----------------------------------[1]

int c_sock,port;
struct sockaddr_in c_addr;
char ip[12];

//------------------------------------------


//part-----------------------------------[2]

char chat[64];
char* dump;

//part--------------------------------------




//main
int main(){
 
//create_socket
 c_sock=socket(AF_INET,SOCK_STREAM,0);
 
 //assign_creds
 c_addr.sin_family=AF_INET;
 while(1){
 //ask_user
 fprintf(stdout,"\e[0;94m[ADDRESS]\e[0;97m: ");
 fscanf(stdin,"%12s",ip);
 fprintf(stdout,"\e[0;94m[PORT]\e[0;97m: ");
 fscanf(stdin,"%12s",&port);
 
 //assign_user_input
 c_addr.sin_port=htons(port);
 inet_aton(ip,&c_addr.sin_addr);
 
 //try_toConnect
 if( connect(c_sock,(struct sockaddr*)&c_addr,sizeof(c_addr)) !=-1 )break;
 else fprintf(stdout,"\e\n\n[0;91mWrong Address Or Port!\n\n");

 //connecting_success
}

//-------------------------COMMUNICATION_SECTION--------------------------
 
 //communicate_until_GetBreakingValue-------------[2]
 while(1){
  
  


















 //comms_ended
}

//---------------------------------ENDED----------------------------------








//esc
 close(c_sock);
 return 0;
}










