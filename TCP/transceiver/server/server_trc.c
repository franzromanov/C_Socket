///////LIBRARY/////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
//////////////////////
//declare
int port,s_sock,c_sock;
struct sockaddr_in ss_addr;//ss(server_socket)
char ip[12];

//::[index_parts]-------[1]
FILE* file;
char filename[]="text2.txt";
char filename_u[32];
char stream[6]={0};
int end=1;
int ack=0;

//main
int main(){
////////////creating_connection//////////////
//user_inp
 fprintf(stdout,"\e[0;91m[IP ADDRESS]\e[0;97m >>> ");
 fscanf(stdin,"%12s",&ip);
 fprintf(stdout,"\e[0;91m[PORT]\e[0;97m >>> ");
 fscanf(stdin,"%d",&port);
 
//create_socket
 s_sock=socket(AF_INET,SOCK_STREAM,0);

 //define_socketADDRESS
 ss_addr.sin_family=AF_INET;
 ss_addr.sin_port=htons(port);
 inet_aton(ip,&ss_addr.sin_addr);

//binding
 bind(s_sock,(struct sockaddr*)&ss_addr,sizeof(ss_addr));

//listening
 listen(s_sock,3);

//accept_connection
 while(1){
 c_sock=accept(s_sock,NULL,NULL);
 if(c_sock!=-1)break;

}

/////////////////////////////////////////////

///////////communication//////////////

//ask_client
 int opt;
 
 //menu
 char main_menu[]="\n\n\e[0;91mwelcome to menu!\n\e[0;97mplease relax and pick an action[ex:1]:\n\n\e[0;91m[1] \e[0;97mDownload_File\n\e[0;91m[2] \e[0;97mUpload_File\n\nyour choice: ";//create_menu
 send(c_sock,main_menu,sizeof(main_menu),0);//send_menu->client
 //get_integer
 read(c_sock,&opt,sizeof(opt));
 //fprintf(stdout,"%d\n",opt);
 
 //transferData_SERVER>>>CLIENT[Downloads]::[index_parts]------------[1]

 if(opt==1){
  
  //sendFilename
  send(c_sock,filename,sizeof(filename),0);
  //read_file
  file=fopen(filename,"r");
  while(fgets(stream,6,file)){

   //sending_eachbyte

   send(c_sock,stream,sizeof(stream),0);
   write(c_sock,&end,sizeof(end));   

  //download_end
}
 for(int i=0;i<6;i++)stream[i]=0;
 send(c_sock,stream,sizeof(stream),0);
 end=2;
 write(c_sock,&end,sizeof(end));
 fclose(file);
}


//transferData_SERVER<<<CLIENT[Upload]::[index_parts]------------[1]
if(opt==2){
 //get_filename
 recv(c_sock,filename_u,sizeof(filename_u),0);
 file=fopen(filename_u,"w");
 while(end!=2){
  //getByte
  
  recv(c_sock,stream,sizeof(stream),0);
  read(c_sock,&end,sizeof(end));
  
  //writing
  if(stream[0]!=0)fprintf(file,"%s",stream);
  
  //done_writing
}
 fclose(file);
//ClientUpload_done
}
//////////////SERVICE_END/////////////////////










//esc
 close(s_sock);
 return 0; 
}
