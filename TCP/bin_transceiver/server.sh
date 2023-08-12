cc -c -g server_sock#2.c
cc -c -g ./talk/talk.c

cc -o server_sock#2 server_sock#2.o ./talk/talk.o

./server_sock#2
