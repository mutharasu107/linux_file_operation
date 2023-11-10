/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 8/11/2023                                                                                */
/*   File name      : rmdir.c                                                                                  */
/*   Description    : delete a directory                                                                       */
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

// First create one directory, In this system call giveing which directory i am delete mation this directory name(ex sam)
// arg[1] is which directory delet that directory name
   // int rmdir(const char *pathname);
   dir = rmdir( argv[1] );
   if( dir == -1 )
   {
	ret_val = errno;
	perror("No such file or Directory");
	exit(-ret_val);
   }
}
