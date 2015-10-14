#include <stdio.h>
int main()
{

  long num,n,i,j,count,max_cycle;

  long tmp,itmp,jtmp;



  while(scanf("%ld %ld",&i,&j)!=EOF)

  {

      if(i==0 && j==0)

          break;

      max_cycle=0;

      itmp=i;

      jtmp=j;

      if(i>j)

      {

          tmp=itmp;

          itmp=jtmp;

          jtmp=tmp;

      }

      for(n=itmp;n<=jtmp;n++)

      {

          num=n;

          count=1;

          while(num!=1)

          {

              if(!(num%2))

              {

                  num/=2;

                  count++;

              }

              else

              {

                  num=(num*3)+1;

                  count++;

              }

              //printf("%d\n",n);

          }

          if(max_cycle < count)

              max_cycle=count;

      }

      printf("%ld %ld %ld\n",i,j,max_cycle);

  }

}
