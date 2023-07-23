//////////LIBRARY////////////
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
////////////////////////////


//declare
struct sockaddr_in c_addr;
int c_sock,port;
char ip[12];

//::[index_parts]-----------------[1]
FILE* file;
char stream1[64];
char filename[32];
int end;
int ack=0;
char filename_u[]="text2.txt";

//main
int main(){
///////////creating_connection//////////
//user_inp
 fprintf(stdout,"\e[0;91m[IP ADDRESS]\e[0;97m >>> ");
 fscanf(stdin,"%12s",ip);
 fprintf(stdout,"\e[0;91m[PORT]\e[0;97m >>> ");
 fscanf(stdin,"%d",&port);

//create_socket
 c_sock=socket(AF_INET,SOCK_STREAM,0);
 //define_address
 c_addr.sin_family=AF_INET;
 c_addr.sin_port=htons(port);
 inet_aton(ip,&c_addr.sin_addr);
//connect

 if(connect(c_sock,(struct sockaddr*)&c_addr,sizeof(c_addr))==-1)fprintf(stdout,"\e[0;91mServer Is Not Active!\n");
 else{

//////////////connected////////////////

 
 //communication
  char stream[256];
  int opt;
  //menu
  recv(c_sock,stream,sizeof(stream),0);//receive_MainMenu
  fprintf(stdout,"%s",stream);
  //action
  fscanf(stdin,"%d",&opt);
  //send_integer
  write(c_sock,&opt,sizeof(opt));
 
 //download_section::[index_parts]------[1]
  if(opt==1){
   
   //getName
   recv(c_sock,filename,sizeof(filename),0);
   file=fopen(filename,"w");
  
   //writing
   while(end!=2){
   
   //getByte
     recv(c_sock,stream1,sizeof(stream1),0);
     read(c_sock,&end,sizeof(end));
   //write
     if(stream1[0]!=0){fputs(stream1,file);}
    
   //done_writing
}
  
  fclose(file);
  //download_end
}

//upload_section::[index_parts]------[1]
 if(opt==2){
  //get_filename
  //sendfilename
  send(c_sock,filename_u,sizeof(filename_u),0);
  //openfile
  file=fopen(filename_u,"r");
  while(fgets(stream1,64,file)){
 
   //sending_eachByte
   send(c_sock,stream1,sizeof(stream1),0);
   write(c_sock,&end,sizeof(end));
   //done_sending

}
 //SENDING_END_CONDITION
 for(int i=0;i<64;i++)stream1[i]=0;
 send(c_sock,stream1,sizeof(stream1),0);
 end=2;
 write(c_sock,&end,sizeof(end));
 fclose(file);
//upload_done

}


//connection_success
}

//esc
 close(c_sock);
 return 0;
}
 
