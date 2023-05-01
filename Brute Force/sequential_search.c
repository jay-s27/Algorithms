/* SEQUENTIAL SEARCH*/

#include<stdio.h>
#include<stdlib.h>

int rightmost_sequential_search(int* arr,int n,int key)
{
    int found=0;
    int i=0;
    while(i<n)
    {
        if(arr[i]==key)
        {
            found++;
        }
        i++;
    }
    if(found=0)
    return -1;
    else 
    return found;
}

int leftmost_sequential_search(int* arr,int n,int key)
{
    int found=-1;
    int i=0;
    while(i<n && arr[i]!=key)
    {
        i++;
    }
    if(found==-1)
    return -1;
    return i;
}

void all_sequential_search(int* arr,int n,int key)
{
    int found=-1;
    int i=0;
    while(i<n)
    {
        if(arr[i]==key)
        {
            printf("%d\n",i);
            found=1;
        }
        i++;
    }
    if(found==-1)
    printf("-1/n");
}



int main()
{
    int n,key;
    scanf("%d",&n);
    int *arr=calloc(n,sizeof(int));
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&key);
    int rans=rightmost_sequential_search(arr,n,key);
    printf("Right most occurance at:%d\n",rans);
    int lans=leftmost_sequential_search(arr,n,key);
    printf("Left most occurance at:%d\n",lans);
    printf("All occurances:\n");
    all_sequential_search(arr,n,key);
    return 0;
}