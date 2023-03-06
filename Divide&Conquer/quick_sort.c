/*QUICK SORT
1) Uses pivots, guiding elements, heuristics
2) PIVOT: refers to the first element of the selected region
3) arr[i] is greater than the pivot (iterates from 0 to n-1)
4) arr[j] is lesser that the pivot (iterates from high to 0)
5) One wrong swap occurs when i>j
6) TIME COMPLEXITY:
    --->Best Case: all splits are at the middle of the array
        T(n)=2T(n/2)+(n+1) {n if i and j coincide}
        T(n) belongs to O(nlogn)
    --->Worst Case: an already sorted array
        T(n)=T(n-1)+(n+1)
    --->Average Case
        C(n)=(1/n) sigma (0->n-1) T(s)+T(n-(s+1))
        C(n)=1.39 nlogn
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(int *arr,int i,int j)
{
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}

int split_pos(int *arr,int n,int low,int high)
{
  int pivot=arr[low];
  printf("pivot%d\n",pivot);
  int i=low;
  int j=high;
 while(i<j)
 {
   do
  {
    i+=1;
  }
  while(arr[i]<=pivot && i!=high-1);
  do
  {
    j-=1;
  }
  while(arr[j]>pivot);
  swap(arr,i,j);
  }
  swap(arr,i,j); //undoing the wrong swap
  swap(arr,low,j); //swapping pivot with arr[j] when i>j
  return j;
}

void quicksort(int *arr,int n,int low,int high)
{
  if(low<high)
  {
    int s=split_pos(arr,n,low,high);
    quicksort(arr,n,low,s-1);
    quicksort(arr,n,s+1,n);
  }

}

int main()
{
  int n;
  scanf("%d",&n);
  int *arr=calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  quicksort(arr,n,0,n);

  for(int i=0;i<n;i++)
  {
    printf("%d	",arr[i]);
  }
  printf("\n");
  return 0;
}