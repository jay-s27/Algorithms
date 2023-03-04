/*RUSSIAN MULTIPLICATION:
  NOTE:
  1) Decrease by constant factor
  2) The first number gets reduced by a factor of 2 and the second number is doubled
  3) T(n) belongs O(logn)
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int russ_mul(int m,int n)
{
  if(m==1)
    return n;
  else
  {
    //if m is even
    if(m%2==0)
      return(russ_mul(m/2,2*n));
    //if m is odd
    else
      return(russ_mul((m/2),2*n)+n);
  }
}

int main()
{
  int m,n;
  scanf("%d",&m);
  scanf("%d",&n);
  //taking a lower value for m
  if(n<m)
  {
    int temp=m;
    m=n;
    n=temp;
  }
  //printf("m:%d n:%d\n",m,n);
  int ans=russ_mul(m,n);
  printf("%d\n",ans);
}