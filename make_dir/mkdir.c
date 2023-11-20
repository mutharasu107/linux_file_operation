/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 8/11/2023                                                                                */
/*   File name      : mkdir.c                                                                                  */
/*   Description    : create a new directory                                                                   */
/***************************************************************************************************************/
#include <sys/stat.h>
#include <sys/types.h>
#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int fd;
   int ret_val = EXIT_SUCCESS;

   mode_t per = S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH;
// In my program argv[1] using this one user given directory name.
   // int mkdir(const char *pathname, mode_t mode);
   fd = mkdir( argv[1], per);
   if(per != 0772)	// 0775 is default permission
   {
	ret_val = errno;
	printf("permission denied\n");
	exit(-ret_val);
   }

   else if( fd == -1 )
   {
	ret_val = errno;
	perror("directory already exists\n");
	exit(-ret_val);
   }

      printf("create new dir name : %s\n", argv[1]);
}
