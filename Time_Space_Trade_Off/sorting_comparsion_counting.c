/* SORTING BY COMPARISON COUNTING
  1) T(n)-O(n^2)+O(n)
*/
#include<stdio.h>
#include<stdlib.h>

void count_table(int *ctable,int *arr,int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
        ctable[i]+=1;
      else
        ctable[j]+=1;
    }
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  int *arr=calloc(n,sizeof(int));
  int *ctable=calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  count_table(ctable,arr,n);
  int *output=calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    output[ctable[i]]=arr[i];
  }

  for(int i=0;i<n;i++)
    printf("%d  ",output[i]);
  printf("\n");
  free(output);
  free(ctable);
  free(arr);
  return 0;
}