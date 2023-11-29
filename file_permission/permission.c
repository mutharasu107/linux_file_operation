/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 29/11/2023                                                                               */
/*   File name      : permission.c                                                                             */
/*   Description    : File Permission Checker                                                                  */
/***************************************************************************************************************/

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
   	str[0] = statbuffer.st_mode & S_IRUSR ? 'r' : '-';
   	str[1] = statbuffer.st_mode & S_IWUSR ? 'w' : '-';
   	str[2] = statbuffer.st_mode & S_IXUSR ? 'x' : '-';
   	str[4] = statbuffer.st_mode & S_IRGRP ? 'r' : '-';
   	str[5] = statbuffer.st_mode & S_IWGRP ? 'w' : '-';
   	str[6] = statbuffer.st_mode & S_IXGRP ? 'x' : '-';
   	str[8] = statbuffer.st_mode & S_IROTH ? 'r' : '-';
   	str[9] = statbuffer.st_mode & S_IWOTH ? 'w' : '-';
   	str[10] = statbuffer.st_mode & S_IXOTH ? 'x' : '-';

	printf("\n File_name inode mode num_of_links uid gid size_in_bytes \n");
	printf("%s %ld %s %ld %d %d %ld\n", argv[iter], statbuffer.st_ino, str, statbuffer.st_nlink, statbuffer.st_uid, statbuffer.st_gid, statbuffer.st_size);
	printf("Last file modification time:   %s", ctime(&statbuffer.st_mtime));
/*   	printf("\nFile name: %s\n", argv[iter]);
   	printf("inode %ld\n", statbuffer.st_ino);
   	printf("mode %s\n", str);
   	printf("num of links %ld\n", statbuffer.st_nlink);
   	printf("uid %d\n", statbuffer.st_uid);
   	printf("gid %d\n", statbuffer.st_gid);
   	printf("size in bytes %ld\n", statbuffer.st_size);*/
   }
   return EXIT_SUCCESS;
}
