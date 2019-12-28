#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
char s[20][20];
int n,m,i,j,t,k;
int cmp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
int main()
{
	while(cin>>s[i])
	{
		if(s[i][0]!='9')
		{
			i++;
			continue;
		}
		m=i;
		t=0;
		qsort(s,m,sizeof(s[0]),cmp);
		for(j=0;j<m;j++)
			if(strncmp(s[j],s[j+1],strlen(s[j]))==0)
			{
				t=1;
				break;
			}
		printf("Set %d is%s immediately decodable\n",++k,t?" now":"");
		i=0;
	}
	return 0;
}
