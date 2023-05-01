/*BUBBLE SORT
  1) Inplace and stable if only >
  2) Inplace and unstable if >=
  3) Time Complexity
     ---> BEST CASE (already sorted list)
          C(n)=n-1
          T(n) belongs to O(n)
     ---> WORST CASE (reverse sort)
          C(n)=n(n-1)/2
          T(n) belongs to O(n^2)
*/

#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *arr,int n)
{
    int swaps=0;
    for(int i=0;i<n-1;i++)
    {
        swaps=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swaps+=1;
            }
        }
        if(swaps==0)
        break;
    }
}

int main()
{
    int n;
    printf("enter number of elements:");
    scanf("%d",&n);
    int *arr=calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
    printf("sorted array\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}