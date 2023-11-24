
/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 23/11/2023                                                                               */
/*   File name      : file_fun.c                                                                               */
/*   Description    :  Create a function that performs file operations on a single file. This function should:
                       Open the file and read its contents.Count the number of lines in the file. 
		       Count the number of words in the file.Close the file after processing.                  */
/***************************************************************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#define BUF 1000000

int main(int argc, char *argv[])
{
   int open_fd, count=0;
   ssize_t read_fd;
   char buf[BUF];
   int ret_val = EXIT_SUCCESS;

   // int open(const char *pathname, int flags);
   open_fd = open( argv[1], O_RDONLY);
   if(open_fd == -1)
   {
      ret_val = errno;
      printf("Error open file\n");
      exit(-ret_val);
   }

   // ssize_t read(int fd, void *buf, size_t count);
   read_fd = read( open_fd, buf, BUF );
   if(read_fd == -1)
   {
      ret_val = errno;
      printf("Error read file\n");
      close(open_fd);
   }
   printf("Read total character count there in file : %ld\n", read_fd);
   // if readfd file descriptor value is less thanor equal to zero means exqute the program
     if(read_fd >= 0)
     {
          for(int i=0; i<read_fd; i++)
          {
               if(buf[i] == 10)    // 10 decimal number is new line ascci value
               {
                    count++;  // frind totally how many lines there in text file
               }
          }
     }
     printf("count line numbers : %d\n", count);
      close(open_fd);
}
