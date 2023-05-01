/*TOPOLOGICAL SORTING USING SOURCE REMOVAL*/
#include<stdio.h>
#include<stdlib.h>

void enqueue(int *q,int n,int val,int *tail)
{
  if((*tail)<n)
  {
    (*tail)+=1;
    q[(*tail)]=val;
  }
}

int dequeue(int *q,int n,int *tail)
{
  if((*tail)==-1)
    return -1;
  else
  {
    int temp=q[0];
    for(int i=1;i<(*tail);i++)
      q[i-1]=q[i];
    (*tail)-=1;
    return temp;
  }
}

void src_removal(int n,int *graph[n],int *indegree,int *out,int *queue,int *tail)
{
  int k=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(graph[j][i]==1)
        indegree[i]++;
    }
  }

  for(int j=0;j<n;j++)
  {
    if(indegree[j]==0)
      enqueue(queue,n,j,tail);
  }

  while((*tail)!=-1)
  {
    int src=dequeue(queue,n,tail);
    for(int j=0;j<n;j++)
    {
      if(graph[src][j]==1)
      {
        graph[src][j]=0;
        indegree[j]--;
        if(indegree[j]==0)
          enqueue(queue,n,j,tail);
      }
    }
    out[k++]=src;
  }
}

int main()
{
  int n;
  printf("enter number of vertices:");
  scanf("%d",&n);
  int *graph[n];
  for(int i=0;i<n;i++)
    graph[i]=malloc(sizeof(int)*n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      scanf("%d",&graph[i][j]);
  }

  int *out=calloc(n,sizeof(int));
  int *indegree=calloc(n,sizeof(int));
  int *queue=calloc(n,sizeof(int));
  int tail=-1;
  src_removal(n,graph,indegree,out,queue,&tail);
  for(int i=0;i<n;i++)
  {
    printf("%d  ",out[i]);
  }
  printf("\n");
  return 0;

}