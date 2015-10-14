#include <stdio.h>
int a[100000][2];
int main(){
  int n,m,x,y,k,i,j,c=0,temp=0,max=0;
  scanf("%d%d",&n,&m);
  while(m--)
  {
    scanf("%d%d%d",&x,&y,&k);
    for(i=x-k;i<x;i++)
      for(j=y-k;j<y;j++)
        if(i+j<=k && i+j>=0){
          a[c][0]=(i>=0)?i:0;
          a[c++][1]=(j>=0)?j:0;
        }
    for(i=0;i<c;i++)
    {
      for(j=1;j<c;j++)
      (a[i][0]==a[i][1] && a[j][0]==a[j][1])? temp++:0;

      if(temp>max)
        max=temp;
    }
  }
  printf("%d",max);
  return 0;
}
