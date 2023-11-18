/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 14/11/2023                                                                               */
/*   File name      : num_directory.c                                                                          */
/*   Description    : Write a program to create 10 directors, 						       */
/*                    one directory has to be created per second, then delete one by one (one per second).     */
/***************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
   int ret_val = EXIT_SUCCESS;
   int mkdir_fd, rmdir_fd;

   for(int i=1; i<argc; i++)
   {
      // creating number of new dir
      // int mkdir(const char *pathname, mode_t mode);
      sleep(1);
      mkdir_fd = mkdir(argv[i], 0775);
      if( mkdir_fd == -1 )
      {
	 ret_val = errno;
 	 perror("Error already file or directory is there\n");

	 // if two folder create same name means now showing error that time before creating folder all so removed.
   	for(int rem=1; rem<argc; rem++)
	{
	   sleep(1);
      	   // int rmdir(const char *pathname);
      	   rmdir(argv[rem]);
	}
	exit(-ret_val);
     }
     else
     {
	 perror("Successfuly open new directory\n");
     }
   }

   // remove before creating all directory in one by one.
   for(int rem=1; rem<argc; rem++)
   {
      // int rmdir(const char *pathname);
      sleep(1);
      rmdir_fd = rmdir(argv[rem]);
      if( rmdir_fd == -1 )
      {
	 ret_val = errno;
	 perror("Error removeing dir\n");
	 exit(-ret_val);
      }
      else
      {
	 perror("Successfuly remove dir\n");
      }
   }
}
