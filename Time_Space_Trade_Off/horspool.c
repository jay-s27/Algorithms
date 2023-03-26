/* HORSPOOL:
   1) Pattern matching
   2) Constructing Shift Table--> O(m)
   3) Simplified version of Boyer-Moore algorithm
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void init_stable(int *shift_table,char* pattern) //creating a shift table
{
  int plen=strlen(pattern);
  for(int i=0;i<26;i++)
  {
    shift_table[i]=plen;
  }

  for(int i=0;i<plen-1;i++)
  {
    int index=pattern[i]-'a';
    shift_table[index]=plen-1-i;
  }
}

void horspool(char *string,char *pattern,int *shift_table)
{
  int plen=strlen(pattern);
  int slen=strlen(string);
  int k=0;
  int end=plen-1; //end marker for 1st window
  while(end<=slen-1)
  {
    k=0; //no of matching characters in window
    while(string[end-k]==pattern[plen-1-k] && k<=plen-1)
    {
      k=k+1;
    }
    if(k==plen)
      printf("PATTERN FOUND AT %d\n",end-(plen-1));
    int next=string[end]-'a';
    end=end+shift_table[next]; //changing window based on the shift value
  }
}

int main()
{
  char *string,*pattern;
  int *shift_table;
  string=malloc(sizeof(char)*1000);
  pattern=malloc(sizeof(char)*100);
  shift_table=calloc(26,sizeof(int));
  printf("STRING:");
  scanf("%s",string);
  printf("PATTERN:");
  scanf("%s",pattern);

  init_stable(shift_table,pattern);
  horspool(string,pattern,shift_table);
  return 0;
}