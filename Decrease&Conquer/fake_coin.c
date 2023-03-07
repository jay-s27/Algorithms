/* FAKE COIN PROBLEM
   1) Decrease by constant factor
   2) Consider a light coin amongst a bunch of heavy coins
   3) TIME COMPLEXITY
      Basic Operation: number of weighings
      W(n)=W(n/2)+1
      T(n) belongs to O(logn)
      Total number of weighings : logn
*/

#include<stdio.h>
#include<stdlib.h>

int sum(int *arr,int start,int end)
{
  int sum=0;
  for(int i=start;i<=end;i++)
  {
    sum+=arr[i];
  }
  return sum;
}

int fake_coin(int *coins,int start,int n)
{
  if(n==start)
  {
    return coins[n];
  }
  else
  {
    if(n%2==0) //even number of coins
    {
      int mid=(n/2);
      int part1=sum(coins,start,mid-1);
      int part2=sum(coins,mid,n-1);
      //printf("even n%d part1:%d part2:%d\n",n,part1,part2);
      if(part1<part2)  //disgarding the heavier part (part2)
	    return (fake_coin(coins,start,mid));
      else if (part1==part2)
	    return -1; //when there is no fake coin
      else 
	    return(fake_coin(coins,mid,n)); //disgarding the heavier part (part1)
    }
    else
    {
      int extra=coins[n-1];
      int mid=n/2;
      int part1=sum(coins,0,mid-1);
      int part2=sum(coins,mid,n-2);

      //printf("odd n%d part1:%d part2:%d\n",n,part1,part2);
      if(part1==part2)
	    return extra;
      else if(part1<part2)
	    return(fake_coin(coins,0,mid));
      else
	    return(fake_coin(coins,mid,n-1));
    }
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  int *coins=calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    scanf("%d",&coins[i]);
  }
  int ans=fake_coin(coins,0,n);
  printf("%d\n",ans);
}