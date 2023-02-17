/* USING BINARY CODES*/
/* NOTE:
   1) decrease by constant number
   2) number of subsets --> 2^n
   2) squashed order of subset
   3) does not satisfy minimal change condition
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void subset(char *set,int n)
{
  int count=0;
  int p=pow(2,n);
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<n;j++)
    {
      //printf("%d\n",(i&(1<<j));
      if(i&1<<j)
	printf("%c",set[j]);
    }
    printf("\n");
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  char *set=malloc(sizeof(char)*n+1);
  scanf("%s",set);
  
  subset(set,n);
}

