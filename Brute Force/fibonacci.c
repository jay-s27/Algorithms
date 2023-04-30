/*FIBONACCI SERIES*/

#include<stdio.h>
#include<stdlib.h>

void fib(int n)
{
    int pprev=0,prev=1,f=0;
    if(n==0)
    pprev=0;
    else if(n==1)
    prev=1;
    else
    {
        printf("%d\n%d\n",pprev,prev);
        for(int i=2;i<n;i++)
        {
            f=pprev+prev;
            pprev=prev;
            prev=f;
            printf("%d\n",f);
        }

    }

}

int main()
{
    int n;
    printf("enter number of terms:");
    scanf("%d",&n);
    fib(n);
    return 0;
}