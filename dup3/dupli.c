/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 03/12/2023                                                                               */
/*   File name      : dupli.c                                                                                  */
/*   Description    : call dup2() by passing stdout as old fd and an unused fd as new fd                       */
/***************************************************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
   int d_dup;
   ssize_t write_size;
   
   //  int dup2(int oldfd, int newfd);
   d_dup = dup2(1, 10);
   if(d_dup < 0)
   {
      perror("dup2 :");
      exit(-1);
   }
   printf("%d\n", d_dup);

   // ssize_t write(int fd, const void *buf, size_t count);
   write_size = write(d_dup, "hi school of linux\n", 19);
   if(d_dup < 0)
   {
      perror("write:");
      exit(-2);
   }
   exit(0);
}
