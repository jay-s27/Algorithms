/* NAIVE STRING MATCHING
   1) Time Complexity
      PATTERN FOUND
        BEST CASE: pattern found in first window
        ---> C(n)=O(m)
        WORST CASE: pattern found in last window
        ---> C(n)=(n-m+1)m =O(mn)

      PATTERN NOT FOUND
        BEST CASE: first comparision fails in every window
        ---> C(n)=1*(n-m+1)=O(n)
        WORST CASE: all comparisions in every window
        ---> C(n)=m*(n-m+1)=O(mn) 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int naive_string(char *string,char *pattern)
{
    int n=strlen(string);
    int m=strlen(pattern);
    int count,num;
    for(int i=0;i<n-m+1;i++)
    {
        count=0;
        num=-1;
        for(int j=0;j<m;j++)
        {
            if(string[i+j]==pattern[j])
            count++;
            else
            break;
        }
        if (count==m)
        {
            num=i;
            break;
        }

    }
    return num;
}

int main()
{
    char *string=malloc(sizeof(char)*1000);
    char *pattern=malloc(sizeof(char)*100);
    printf("string:");
    scanf("%s",string);
    printf("pattern:");
    scanf("%s",pattern);
    int ans=naive_string(string,pattern);
    printf("pattern found at:%d\n",ans);
}