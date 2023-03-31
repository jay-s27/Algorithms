#include<stdio.h>
#include<stdlib.h>

void init_arr(int n,int matrix[n][n],int *d,int* p,int src)
{
    for(int i=0;i<n;i++)
    {
        d[i]=9999;
        p[i]=-1;
    }
    d[src]=0;
    p[src]=0;
}

int find_min(int *d,int *s,int n)
{
    int res,min=9999;
    int i;
    for(i=0;i<n;i++)
    {
        if(d[i]<min && d[i]!=0 &&s[i]==0)
        {
            min=d[i];
            res=i;
        }
    }
    return res;
}

void relax_edge(int n,int matrix[n][n],int *d,int *p,int u,int v)
{
    if(d[v]>(d[u]+matrix[u][v]))
    {
        d[v]=d[u]+matrix[u][v];
        p[v]=u;
    }
}

void dijkstra(int n,int matrix[n][n],int *d,int *p,int *s,int src,int dest)
{
    int u;
    for(int i=0;i<n;i++)
    {
        s[i]=0;
    }
    init_arr(n,matrix,d,p,src); //setting src value to 0

    for(int i=0;i<n;i++)
    {
        u=find_min(d,s,n);
        s[u]=1;
        for(int v=0;v<n;v++)
        {
            if(s[v]==0 && matrix[v][u]!=0)
            {
                relax_edge(n,matrix,d,p,u,v);
            }
        }
    }
}

void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}

int main()
{
    int n,src,dest;
    scanf("%d",&n);
    scanf("%d",&src);
    scanf("%d",&dest);
    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    int d[n],p[n],v[n];
    dijkstra(n,matrix,d,p,v,src,dest);
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n;j++)
        {   if(i!=j)
            {
                printf("%d-->%d     %d\n",i,j,abs(d[j]-d[i]));
            }
        }
    }
}