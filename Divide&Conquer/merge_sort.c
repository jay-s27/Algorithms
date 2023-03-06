/*MERGE SORT
1) Divide and Conquer method
2) This code uses auxiliary space in the merge phase
3) Effort spent in divide phase is 1
4)Merge is more expensive
5) TIME COMPLEXITY:
    Basic op: A[i]<=A[j]
    C(n)=2C(n/2)+f(n)
    --->Best Case: when all nos come from 1 region at every phase
        C(n)=2C(n/2)+n/2
        T(n)=2T(n/2)+O(n)
        T(n) belongs to O(nlogn)
    --->Worst Case: numbers get copied in alternating fashion
        C(n)=2C(n/2)+n-1
        T(n)=2T(n/2)+O(n)
        T(n) belongs to O(nlogn)
    --->Average Case
        T(n) belongs to O(nlogn)

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void init(int *arr,int n)
{
  for(int i=0;i<n;i++)

  {
    int r=rand()%1000000;
    arr[i]=r;
  }
}

void merge(int *arr,int low,int mid,int high)
{
  int i=low;
  int j=mid+1;
  int k=low;
  int *temp=calloc(high+1,sizeof(int));
  while(i<=mid && j<=high)
  {
    if(arr[i]<=arr[j])
    {
      temp[k]=arr[i];
      i++;
      k++;
    }
    else
    {
      temp[k]=arr[j];
      j++;
      k++;
    }
  }
  while(i<=mid)
  {
    temp[k]=arr[i];
    i++;
    k++;
  }
  while(j<=high)
  {
    temp[k]=arr[j];
    j++;
    k++;
  }

  for(int m=low;m<=high;m++)
    arr[m]=temp[m];
}

void mergesort(int *arr,int low,int high)
{
  int mid;
  if(low<high)
  {
    mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}

int main()
{
  int n;
  int *arr;
  arr=calloc(n,sizeof(int));
  init(arr,n);
  mergesort(arr,0,n-1);
  for(int j=0;j<n;j++)
  {
    printf("%d ",arr[j]); 
  }
  printf("\n");
  return 0;
}