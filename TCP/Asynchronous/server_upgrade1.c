//---------LIBRARIES-----------*
#include <stdio.h>             
#include <string.h>            
#include <arpa/inet.h>         
#include <netinet/in.h>        
#include <unistd.h>            
#include <sys/socket.h>        
#include <sys/types.h>         
#include <stdlib.h>
#include <fcntl.h>            
//-----------------------------*

/*
//////how_to_establish_a_communication////
-create_socket
-bind_socket
-listen_forConnectionRequest
-accept_connection
-Communicate[send/recieve]
-CommunicationEnded[CLOSE]
//////////////////////////////////////////
*/

//declare_variables

//part----------------------------------------[1]

struct sockaddr_in s_addr;//:::::addr_struct
int s_sock;//:::::store_SocketCredentials
int port,counter;
char ip[12]="192.168.1.8";
char admin[]= "Neo_Crackers";
char password[]= "Eleutheria2812";
char _askAdmin[13];
char _askPassword[15];

//-----------------------------------------------


//part----------------------------------------[2]
int c_sock;
char trc[64];
char *dump;
fd_set trc_fd;
//-----------------------------------------------





//main
int main(){
//------------------------------------ASKING_SOME_CREDENTIALS--------------------------------------[1]
 
 //ask_until_SomeAttempts
 while(1){
  //conditions
  if(counter==3){fprintf(stdout,"\n\n\e[0;91m[SYS_OUT]\e[0;97m:NO_MORE_ATTEMPTS!!!\n\n");exit(1);}
  
  fprintf(stdout,"\e[0;94m[USERNAME]\e[0;97m: ");
  fscanf(stdin,"%s",_askAdmin);
  fprintf(stdout,"\e[0;94m[PASSWORD]\e[0;97m: ");
  fscanf(stdin,"%s",_askPassword);
  
  //conditions
  if(strcmp(_askAdmin,admin)!=0 || strcmp(_askPassword,password)!=0){
   
   fprintf(stdout,"\n\n\e[0;91mWRONG CREDENTIALS, please try again!\n\n");
   counter++;
} 
  else break;

}
 //creds_assign[SUCCESS]
 fprintf(stdout,"\e[0;94m[PORT]\e[0;97m: ");
 fscanf(stdin,"%d",&port); 
 
//----------------------------------------------DONE---------------------------------------------------



//create_socket---------------------------[1]
 s_sock=socket(AF_INET,SOCK_STREAM,0);
 
 //pass_credentials
 s_addr.sin_family=AF_INET;
 s_addr.sin_port=htons(port);
 inet_aton(ip,&s_addr.sin_addr);
//-------------------DONE-----------------//
 

//bind_socket-----------------------------------------**
 bind(s_sock,(struct sockaddr*)&s_addr,sizeof(s_addr));

//listen_forConnectionRequests------------------------**
 listen(s_sock,3);


//non_blocking[set]-------------------------------[2]
 fcntl(c_sock,F_SETFL,0_NONBLOCK);


//accepting_request-----------------------------------**
 c_sock=accept(s_sock,NULL,NULL);



 
//---------------COMMUNICATION_SECTION----------------**

 //talk_until_GotBreakValue----------------[2]
 while(1){
  
  //Set_FileDescriptor
    FD_ZERO(&trc_fd);
    FD_SET(s_sock,&trc_fd)
  //accepting_request-----------------------[2]
  c_sock=accept(s_sock,NULL,NULL);
















}

//------------------------DONE------------------------**

//esc
 close(s_sock);
 return 0;
}











