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
char ip[16]="127.0.0.1";
char admin[]= "E";//"Neo_Crackers";
char password[]= "E";//"Eleutheria2812";
char _askAdmin[13];
char _askPassword[15];
//-----------------------------------------------


//part----------------------------------------[2]
int c_sock;
char trc[256];
char *dump;
char _usr_cli[]="EA_NASIR";
char _pass_cli[]="copper_notgood666";
typedef struct User_Creds{
 char name[256];
 char password[64];
}LOG_IN;

LOG_IN creds;

//-----------------------------------------------

//main
int main(){
//------------------------------------ASKING_SOME_CREDENTIALS--------------------------------------[1]

 //ask_until_SomeAttempts
 while(1){
  //conditions
  if(counter==3){fprintf(stdout,"\n\n\e[0;91m[SYS_OUT]\e[0;97m:NO_MORE_ATTEMPTS!!!\n\n");exit(1);}

  fprintf(stdout,"\e[0;94m[USERNAME]\e[0;97m: ");
  fscanf(stdin,"%13s",_askAdmin);
  fprintf(stdout,"\e[0;94m[PASSWORD]\e[0;97m: ");
  fscanf(stdin,"%15s",_askPassword);

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

//accepting_request-----------------------------------**
 c_sock=accept(s_sock,NULL,NULL);




//---------------COMMUNICATION_SECTION----------------**

 //talk_until_GotBreakValue----------------[2]

  //LOGIN_PAGE------------------[LOCAL:1]
  //header
  char header[]="\e[0;94m**************************************************\n|------------:::::\e[0;33mSILIMMA_HEMEEN\e[0;94m:::::------------|\n**************************************************\n|\e[47m                                                \e[0;0m\e[0;94m|\n|\e[47m                                                \e[0;0m\e[0;94m|\n|\e[47m                   \e[0;30m\e[47mLOGIN_PAGE                   \e[0;0m\e[0;94m|\n|\e[47m                                                \e[0;0m\e[0;94m|\n|\e[47m                                                \e[0;0m\e[0;94m|\n|------------------------------------------------|\n|================================================|\n";
  char* head_send;
  int len_header=sizeof(header)+1;
  head_send=malloc(sizeof(char)*(len_header));
  strcpy(head_send,header);
  head_send[len_header-1]=-1;

  //usr_field
  char usr_field[]="| \e[0;91m<<\e[0;91m[\e[0;97mUSERNAME\e[0;91m]\e[0;91m>>\e[0;97m ";
  char* usr_send;
  int len_usr=sizeof(usr_field)+1;
  usr_send=malloc(sizeof(char)*len_usr);
  strcpy(usr_send,usr_field);
  usr_send[len_usr-1]=-2;


  //pass_field
  char pass_field[]="\e[0;94m| \e[0;91m<<\e[0;91m[\e[0;97mPASSWORD\e[0;91m]\e[0;91m>>\e[0;97m ";
  char* pass_send;
  int len_pass=sizeof(pass_field)+1;
  pass_send=malloc(sizeof(char)*(len_pass));
  strcpy(pass_send,pass_field);
  pass_send[len_pass-1]=-2;
  //fprintf(stdout,"%d\n",head_send[len_header-1]);

 //BEGIN_TO_ASK--------------------------------[2][LOCAL:1]
 //sending_HEADER
 send(c_sock,head_send,len_header,0);

 //asking_creds
 while(1){

  //ask_usr
  send(c_sock,usr_send,len_usr,0);
  printf("done\n");
  recv(c_sock,creds.name,sizeof(creds.name),0);

  //ask_pass
  send(c_sock,pass_send,len_pass,0);
  printf("done\n");
  recv(c_sock,creds.password,sizeof(creds.password),0);

  //check_ans
  if( strcpy(creds.name, _usr_cli)==0 && strcpy(creds.password, _pass_cli)==0 ){int stat=-3;send(c_sock,&stat,sizeof(stat),0); break; }
  else continue;

}

//------------------------DONE------------------------**

//esc
 close(s_sock);
 printf("gg\n");
 return 0;
}
