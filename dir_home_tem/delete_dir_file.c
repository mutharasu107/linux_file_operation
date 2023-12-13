#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   int rm_dir,un_lk, at;
   
   printf("pass the argv[1] is directory name : \n");
   printf("pass the argv[2] is any file name : \n");

   // int rmdir(const char *pathname);
   rm_dir = rmdir(argv[1]);
   if(rm_dir < 0)
   {
      perror("rmdir : Error");
      exit(-2);
   }

   // int unlink(const char *pathname);
   un_lk = unlink(argv[2]);
   if(un_lk < 0)
   {
      perror("unlink : Error");
      exit(-1);
   }
}
