/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 8/11/2023                                                                                */
/*   File name      : chmod.c                                                                                  */
/*   Description    : change permissions of a file                                                             */
/***************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
   int change_per;
   int rt_val = EXIT_SUCCESS;

   int a = atoi(argv[1]);
// add any file in this directory(ex file.txt), clearly menssion which file you have to change permmission
   // int chmod(const char *pathname, mode_t mode);
   change_per = chmod("file.txt", a);
   if( change_per == -1 )
   {
      rt_val = errno;
      perror("not there in this file");
      exit(-rt_val);
   }
}
