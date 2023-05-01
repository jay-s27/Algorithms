/* NAIVE STRING MATCHING
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