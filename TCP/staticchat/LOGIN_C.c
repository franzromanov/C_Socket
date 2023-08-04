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
char ip[16];
int length;
//------------------------------------------


//part-----------------------------------[2]

char trc[256];
int stat=0;
int ack=66;

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
 fscanf(stdin,"%16s",ip);
 fprintf(stdout,"\e[0;94m[PORT]\e[0;97m: ");
 fscanf(stdin,"%d",&port);

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
  //end_of_comms
  if(stat==-3)break;
 while(1){
  //get_fromserver
  recv(c_sock,trc,sizeof(trc),0);

  //for_header
  if(trc[0]==-1){send(c_sock,&ack,sizeof(ack),0);break;}
  if(trc[0]==-3){stat=-3;break;}
  //for_userinteract
  if(trc[0]==-2){

   //ask
   fscanf(stdin,"256%s",trc);

   //send
   send(c_sock,trc,sizeof(trc),0);

  break;
}
  //check_stringsField
  length=strlen(trc);


  //for_header
  if(length<256 && trc[length+1]==-1){fprintf(stdout,"%s",trc);send(c_sock,&ack,sizeof(ack),0);break;}

  //print_toConsole
  fprintf(stdout,"%s",trc);

  //for_userinteract
  if(length<256 && trc[length+1]==-2){

   //ask
   fscanf(stdin,"%s",trc);
   //fprintf(stdout,"%s",trc);
   //send
   send(c_sock,trc,sizeof(trc),0);

   break;
}

}
  
 //comms_ended
}

//---------------------------------ENDED----------------------------------

//esc
 close(c_sock);
 return 0;
}
