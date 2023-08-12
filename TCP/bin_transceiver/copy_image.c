#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declare
FILE* img;
FILE* cpy;

int _bin;

//main
int main(){

//open_file
 img=fopen("./img/uwu.png","rb"); 
 cpy=fopen("copy.png","wb");
 while((_bin=fgetc(img))!=EOF)fputc(_bin,cpy);

//close_file
 fclose(img);
 fclose(cpy);

//esc
 return 0;
}
