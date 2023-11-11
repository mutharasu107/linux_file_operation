/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 8/11/2023                                                                                */
/*   File name      : mkdir.c                                                                                  */
/*   Description    : create a new directory                                                                       */
/***************************************************************************************************************/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>

int main(int argc, char *argv[])
{
   int dir;
   int ret_val = EXIT_SUCCESS;

// In my program argv[1] using this one user given directory name, argv[2] is permission for directory given user.
   // int mkdir(const char *pathname, mode_t mode);
   dir = mkdir( argv[1], 0775 );
   if( dir == -1 )
   {
	ret_val = errno;
	perror("directory already exists");
	exit(-ret_val);
   }
}
