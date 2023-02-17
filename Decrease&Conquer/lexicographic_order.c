#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void arr_init(int *arr,int n)
{
  for(int i=0;i<n;i++)
    arr[i]=i+1;
}

void print(int *arr,int n)
{
  for(int i=0;i<n;i++)
    printf("%d	",arr[i]);
  printf("\n");
}

int fact(int n)
{
  int prod=1;
  while(n>0)
  {
    prod*=n;
    n=n-1;
  }
  return prod;
}

int farthest(int *arr,int n)
{
  int a,b;
  for(int i=0;i<n-1;i++)
  {
    if(arr[i]<arr[i+1])
    {
      a=arr[i];
    }
  }
  return a;
}

int search(int *arr,int find,int n)
{
  for(int i=0;i<n;i++)
  {
    if(arr[i]==find)
      return i;
  }
  return -1;
}

int largest(int *arr,int ai,int i,int n)
{
  int res=-1;
  for(int k=i+1;k<n;k++)
  {
    if(arr[k]>ai)
      res=arr[k];
  }
  return res;
}

void reverse(int *arr,int i,int n)
{
  int temp;
  int c=0;
  int tarr[100];
  for(int k=n-1;k>i;k--)
  {
    tarr[c]=arr[k];
    //printf("arr[k]:%d\n",arr[k]);
    c++;
  }
  int r=0;

  for(int k=i+1;k<n;k++)
  {
    arr[k]=tarr[r];
    r++;
  }
 // printf("reverse:");
 // print(tarr,c);
}

int main()
{
  int n,count=0;
  scanf("%d",&n);
  int *arr=calloc(n,sizeof(int));
  arr_init(arr,n);
  print(arr,n);
  int k=fact(n);
  int ai,aj,i,j,temp;
  while(count<k-1)
  {
    ai=farthest(arr,n);
    i=search(arr,ai,n);
    aj=largest(arr,ai,i,n);
    j=search(arr,aj,n);
    //printf("ai%d aj%d i%d j%d\n",ai,aj,i,j);
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    reverse(arr,i,n);
    print(arr,n);
    count++;

  }
  
}