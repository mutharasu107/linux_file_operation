k/***************************************************************************************************************/
/*   Author         : Mutharsu R                                                                               */
/*   Date           : 03/01/2024                                                                               */
/*   File name      : readv_line.c                                                                             */
/*   Description    :  Read a text file, identify number of lines in the file, write each line in different    */
/*     		       files using readv() Also print the file position.                                       */
/***************************************************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

int *ptr = (int *)malloc(argv[1]);
#define BUF *ptr

int main(int argc, char *argv[])
{
   int open_fd,i,j,k,a,new_fd;
   char buf[BUF+1];
   char buf1[BUF+1];
   ssize_t read_bytes, wrt_bytes;
   char file[8] = "split00";
   
   buf[BUF]='\0';

   if(argc < 2)
   {
      perror("please give any text file");
      exit(-1);
   }

   // int open(const char *pathname, int flags);
   open_fd = open( argv[1], O_RDONLY);
   if(open_fd < 0)
   {
      perror("open() : Error open text file");
      exit(-2);
   }

   //  ssize_t read(int fd, void *buf, size_t count);
   read_bytes = read( open_fd, buf, BUF);
   if(read_bytes < 0)
   {
      perror("read() : Error read a file");
      close(open_fd);
      exit(-3);
   }

   for( i=0, j=0, k=0; i<read_bytes; i++ )
   {
      if(buf[i] == '\n')
      {
	 buf1[j] = buf[i];
	 
	 new_fd = open(file, O_CREAT | O_WRONLY, 0644);
	 if(new_fd < 0)
	 {
	    perror("open() : Error creating new file\n");
	    close(open_fd);
	    exit(-4);
	 }

	 wrt_bytes = write(new_fd, buf1, j+1);
	 if(wrt_bytes < 0)
	 {
	    perror("write() : Error wrting a file %ld");
	    close(open_fd);
	    close(new_fd);
	    exit(-5);
	 }

	 close(open_fd);
	 j=0;
	 k++;
	 a=k%10;
	 file[6] = a + '0'; 
	 a=k/10;
	 file[5] = a + '0';
      }
      else
      {
	 buf1[j++] = buf[i];
      }
   }
   close(open_fd);
   exit(-6);
}
