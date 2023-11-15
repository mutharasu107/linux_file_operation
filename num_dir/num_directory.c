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
   
   for(int i=1; i<argc; i++)
   {
      int fd[argc];
      // int mkdir(const char *pathname, mode_t mode);
      fd[argc] = mkdir(argv[i], 0775);
      sleep(1);
      if( fd[argc] == -1 )
      {
	 ret_val = errno;
	 perror("Error already directory is theren\n");
	 exit(-ret_val);
      }
      else
      {
	 perror("Successfuly open new directory\n");
      }
   }
   for(int rem=1; rem<argc; rem++)
   {
      int arr[argc];
      // int rmdir(const char *pathname);
      arr[argc] = rmdir(argv[rem]);
      sleep(1);
      if( arr[argc] == -1 )
      {
	 ret_val = errno;
	 perror("Error removeing folder\n");
	 exit(-ret_val);
      }
      else
      {
	 perror("Successfuly remove dir\n");
      }
   }
}

