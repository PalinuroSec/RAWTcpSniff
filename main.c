#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "main.h"

int main(void) {
   int i, recv_length, sockfd;
   u_char buffer[9000];

   if ((sockfd = socket(PF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
      fatal("in socket");
   printf("welcome to FrozenBox tools - RAW sniffer\nfor more info visit www.frozenbox.org\n\n\t sniffing....\n\n");

   do {
      recv_length = recv(sockfd, buffer, 8000, 0);
      printf("\n\tGot a %d byte packet\n", recv_length);
      dump(buffer, recv_length);
   }
   while(1);
}
