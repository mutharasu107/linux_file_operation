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

const char *path = "sam";

int main()
{
   int dir;
   int ret_val = EXIT_SUCCESS;

// First create one directory, In this system call giveing which directory i am delete mation this directory name(ex sam)
   // int rmdir(const char *pathname);
   dir = rmdir( path );
   if( dir == -1 )
   {
	ret_val = errno;
	perror("No such file or Directory");
	goto close_exit;
   }

// close exit file
close_exit:
   close(-ret_val);
}
