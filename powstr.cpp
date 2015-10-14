#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
 int i,j,k,power,len;
 char s[1000005];
 bool ans;

 //freopen("i.txt", "r", stdin);
 //freopen("o.txt", "w", stdout);

 while(scanf("%s", &s) == 1){
  if(!strcmp(s, "."))break;

  len = strlen(s);
  for(i = 1; i <= len; i++){
   if(len % i == 0){
    power = len / i;
    ans = true;
    for(j = 0; j < i; j++){
     for(k = j + i; k < len; k += i){
      if(s[j] != s[k]){
       ans = false;
       break;
      }
     }
    }
    if(ans)break;
   }
  }
  printf("%d\n", power);
 }

 return 0;
}
