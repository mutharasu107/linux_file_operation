#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <error.h>
#include <err.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
   struct timespec st_mtim;  /* Time of last modification */
   struct stat statbuffer;
   int ret;
   int iter=0;
   char *error_message;

   if(argc < 2) 
   {
      fprintf(stderr,"please pass a file name\n");
      exit(-1);
   }

   for(iter=1; iter<argc; iter++) 
   {
        char str[11] = "--- --- ---";
   	ret = stat(argv[iter], &statbuffer);
   	if(ret < 0) 
	{
	        ret = errno;
		error_message = strerror(errno);
		fprintf(stderr, "%s: %s\n", argv[iter], error_message);
		continue;
   	}

	printf("Last file modification time:   %s", ctime(&statbuffer.st_mtime));
   }
   return EXIT_SUCCESS;
}
