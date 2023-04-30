/*MAX ELEMENT IN AN ARRAY*/
#include<stdio.h>
#include<stdlib.h>

int max_element(int *arr,int n)
{
    int maxval=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxval)
        maxval=arr[i];
    }
    return maxval;
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
    int ans=max_element(arr,n);
    printf("Max value:%d\n",ans);
    return 0;
}