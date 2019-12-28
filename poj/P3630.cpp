#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
char h[10020][12];
int n,m,i,t;
int cmp(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		t=0;
		scanf("%d",&m);
		for(i=0;i<m;i++)
			cin >> h[i];
		qsort(h,m,sizeof(h[0]),cmp);
		for(i=0;i<m;i++)
			if(strncmp(h[i],h[i+1],strlen(h[i]))==0)
				{
				t=1;
				break;
				}
		if(t==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}