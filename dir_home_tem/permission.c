#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(int arguc, char *arguv[])
{
    int ret = 0,bit_shift = 0, buf;
    mode_t mode = 0, temp;

    // Octol permisions
    int per[]={00,01, 02, 03, 04, 05, 06, 07};

    // check the permision like read, write or execuite
    while(*(arguv[2]+ret) != '\0')
    {
      // change the values character to integer
      buf = *(arguv[2]+ret);
      buf -= 48;

      // chaeck the permision valid input or not
      if(buf <=7 && buf >=0 )
      {
          //  shifiting and collect givern permisions
           temp =  per[buf] << bit_shift;     
           mode |= temp;

           // move to next per[0]<<0 = like others, per[1]<<3 = group, per[2]<<3 = user
           bit_shift += 3;
      }
      // if faild
      else
      {
          printf("Enter valid octal input\n");
          exit(-1);
      }
      ret++;
    }
   
   // set permision to destination file 
   ret = chmod(arguv[1], mode); 

   //  if pass
   if( ret == 0)
   {
       perror("chmode() : ");
       exit(-2);
   }
   // if fail
   else if (ret > 0)
   {
       perror("chmode() : ");
   }
}
