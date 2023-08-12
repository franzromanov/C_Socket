//-----STANDARD_LIBRARY----
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
//-------------------------

typedef struct CREDS{

 char name[256];
 char password[256];


}creds;

//AdminLogin_session---------------------------------
void _MENU();
int _USER_CREDS(creds* usr_main,creds usr_cmp);


/*
//communication_session------------------------------
//send_text
int say_txt(int sock,int buffer,FILE* txt);

//recv_text
int listen_txt(int sock,int buffer,FILE* txt);


//send_bin
int say_bin();


//recv_bin
int listen_bin();
*/
