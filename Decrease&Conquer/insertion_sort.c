/*INSERTION SORT
  1) Time Complexity
     BEST CASE: already in ascending
     ---> C(n)=n+1=O(n)
     WORST CASE: in descending order
     ---> C(n)=n(n-1)/2=O(n^2)
*/

#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int *arr,int n)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0)
        {
            if(key<arr[j])
            {
                arr[j+1]=arr[j];
            }
            else
            break;
            j--;
        }
        arr[j+1]=key;
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
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}