#include "talk.h"


//AdminLogin_session---------------------------------

//LoginMenu
void _MENU(){

char header[]="\e[0;94m**************************************************\n|------------:::::\e[0;33mSILIMMA_HEMEEN\e[0;94m:::::------------|\n**************************************************\n|\e[47m                                                \e[0;0m\e[0;94m|\n|\e[47m                                                \e[0;0m\e[0;94m|\n|\e[47m                   \e[0;30m\e[47mLOGIN_PAGE                   \e[0;0m\e[0;94m|\n|\e[47m                                                \e[0;0m\e[0;94m|\n|\e[47m                                                \e[0;0m\e[0;94m|\n|------------------------------------------------|\n|================================================|\n";
fprintf(stdout,"%s",header);

};

//AskingCreds
int _USER_CREDS(creds *usr_main,creds usr_cmp){

 //ask
 fprintf(stdout,"\n\e[0;94m[USERNAME]\e[0;97m: ");
 fscanf(stdin,"%s",usr_main->name);
 fprintf(stdout,"\n\e[0;94m[PASSWORD]\e[0;97m: ");
 fscanf(stdin,"%s",usr_main->password);
 
 if( strcmp(usr_main->name,usr_cmp.name)==0 && strcmp(usr_main->password,usr_cmp.password)==0 )return 1;
 else return 0;

};





