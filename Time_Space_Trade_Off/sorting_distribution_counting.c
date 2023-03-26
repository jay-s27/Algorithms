/*SORTING BY DISTRIBUTION COUNTING:
  1) Constraint when the range is limited
     --> upper-lower << n
  2) Number of keys = upper-lower+1
  3)    
*/

#include<stdio.h>
#include<stdlib.h>

int find_min(int *arr,int n)
{
  int m=9999;
  for(int i=0;i<n;i++)
  {
    if(arr[i]<m)
      m=arr[i];
  }
  return m;
}

int find_max(int *arr,int n)
{
  int m=0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]>m)
      m=arr[i];
  }
  return m;
}

void dist_count(int *count,int *arr,int *output,int range,int n,int l)
{
  int index;
  for(int i=0;i<n;i++)  //O(u-l+1) --> O(u-l)
  {
    index=arr[i]-l;    //convert key to index value (key-lower)
    count[index]+=1;
  }
  for(int i=0;i<range;i++) //O(u-l)
  {
    count[i]=count[i]+count[i-1];
  }

  for(int i=0;i<n;i++)  //O(n) generate output array
  {
    index=arr[i]-l;
    output[count[index]-1]=arr[i];
    count[index]-=1;
  }
}

int main()
{
  int n,min_val,max_val;
  scanf("%d",&n);
  int *arr=calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  min_val=find_min(arr,n);
  max_val=find_max(arr,n);

  int *output=calloc(n,sizeof(int));
  int range=max_val-min_val+1;   //upper-lower
  int *count=calloc(range,sizeof(int));
  dist_count(count,arr,output,range,n,min_val);
  for(int i=0;i<n;i++)
    printf("%d  ",output[i]);
  printf("\n");
  return 0;
}