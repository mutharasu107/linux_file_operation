#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a=1;
   for(a; a<10; a++)
   {
      if(a==6)
      {
	 exit(0);
      }
      printf("%d\n", a);
   }
}
