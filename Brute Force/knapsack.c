#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void findbin(int *bin,int num,int n)
{
  int i=0;
  for(i=n-1;i>=0;i--)
  {
    bin[i]=num%2;
    num=num/2;
  }
}

int main()
{
  int n,w;
  scanf("%d",&n);
  int v[n];
  int wt[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&v[i]);
  }

  for(int i=0;i<n;i++)
  {
    scanf("%d",&wt[i]);
  }
  printf("wt\n");
  scanf("%d",&w);
  int *bin=calloc(n,sizeof(int));
  int range;
  range=(int)(pow(2,n)+ 1e-9);
  printf("range%d\n",range);
  int max=0;
  while(range>=0)
  {
    int twt=0,tval=0;
    findbin(bin,range,n);
    for(int j=0;j<n;j++)
    {
      //int twt=0,tval=0;
      if(bin[j]==1)
      {
	if(twt<=w)
	{
	  twt+=wt[j];
	  tval+=v[j];
	}
      }
    
      //printf("twt%d	tval:%d\n",twt,tval);
    }
    if(tval>max && twt<=w)
      max=tval;
    range--;
  }

  printf("%d\n",max);

}