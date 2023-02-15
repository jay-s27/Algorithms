#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct arr
{
  int data;
  int flag; //flag 0: l->r
  	    //flag 1: r->l
};

typedef struct arr ARR;

void arr_init(ARR *arr,int n)
{
  for(int i=0;i<n;i++)
  {
    arr[i].data=i+1;
    arr[i].flag=1;
  }
}

void print(ARR *arr,int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%d(%d)	",arr[i].data,arr[i].flag);
  }
  printf("\n");
}

//function to find mobile
int find_mobile(ARR *arr,int n)
{
  int max=0,f;
  for(int i=0;i<n;i++)
  {
    f=arr[i].flag;
    if(f==1 && i!=0)
    {
      if(arr[i].data>arr[i-1].data && arr[i].data>max)
      {
	max=arr[i].data;
      }
    }

    else if(f==0 && i!=n-1)
    {
      if(arr[i].data>arr[i+1].data && arr[i].data>max)
      {
	max=arr[i].data;
      }
    }
  }
  return max;
}

int search(ARR *arr,int find,int n)
{
  for(int i=0;i<n;i++)
  {
	if(find==arr[i].data)
	  return i;
  }
  return -1;
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

void reverse(ARR *arr,int mobile,int n)
{
  for(int i=0;i<n;i++)
  {
    if(arr[i].data>mobile)
    {
      arr[i].flag=1-arr[i].flag;
    }
  }
}

int main()
{
  int n;
  ARR temp;
  scanf("%d",&n); //range of permutation
  int mobile=-1,count=0,i;
  ARR *dataset;
  dataset=malloc(sizeof(ARR)*n);
  arr_init(dataset,n);
  print(dataset,n);
  int k=fact(n);
  printf("fact:%d\n",k);
  while(count<k-1)
  {
    mobile=find_mobile(dataset,n);
    printf("mobile%d\n",mobile);
    i=search(dataset,mobile,n);
    if(i!=0 && dataset[i].flag==1)
    {
      temp=dataset[i];
      dataset[i]=dataset[i-1];
      dataset[i-1]=temp;
    }

    else if(i!=n-1 && dataset[i].flag==0)
    {
      temp=dataset[i];
      dataset[i]=dataset[i+1];
      dataset[i+1]=temp;
    }
    reverse(dataset,mobile,n);
    /*for(int i=0;i<n;i++)
    {
      if(dataset[i].data>mobile)
      {
	dataset[i].flag=1-dataset[i].flag;
      }
    }*/
    print(dataset,n);
    count++;

  }

}