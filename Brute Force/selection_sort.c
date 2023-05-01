/*SELECTION SORT
  1) Unstable algorithm (does not retain order of duplicates)
  2) Inplace algorithm
  3) Time Complexity
     --> C(n)=n(n-1)/2
     --> T(n) belongs to O(n^2) 
*/

#include<stdio.h>
#include<stdlib.h>

void selection_sort(int *arr,int n)
{
    int i=0,minpos;
    for(i;i<n-1;i++)
    {
        minpos=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minpos])
            {
                minpos=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minpos];
        arr[minpos]=temp;
    }
}

int main()
{
    int n;
    printf("number of elements:");
    scanf("%d",&n);
    int *arr=calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,n);
    printf("sorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}