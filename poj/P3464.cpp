#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t[1000020][10];
int f[1000020];
int g[1000020];
int sz[1000020];
char s[500000];
int tot=1,n;
void ins(char *s)
{
	int p=1,q=1;
	for(;*(s+1);s++)
	{
		int u=*(s+1)-'0';
		if(*s-'0'+(u>4)<10)
		{
			if(!t[p][(*s-'0'+(u>4))%10])
				t[p][(*s-'0'+(u>4))%10]=++tot;
			q=t[p][(*s-'0'+(u>4))%10];
		}
		else
		{
			if(!t[q][(*s-'0'+(u>4))%10])
				t[q][(*s-'0'+(u>4))%10]=++tot;
			q=t[q][(*s-'0'+(u>4))%10];
		}
		if(!t[p][*s-'0'])
			t[p][*s-'0']=++tot;
		p=t[p][*s-'0'];
		sz[q]++;
	}
}
int main()
{
	scanf("%d",&n);
	t[1][0]=++tot;
	t[1][1]=++tot;
	for(int i=0;i<n;i++)
	{
		memset(s,0,sizeof s);
		scanf("%s",s);
		s[strlen(s)]='0';
		s[1]='0';
		ins(s+1);
	}
	for(int i=1;i<=tot;i++)
	{
		printf("%d\n",sz[i]);
	}
	for(int i=4;i<=tot;i++)
		for(int j=0;j<10;j++)
			if(t[i][j])
				sz[t[i][j]]+=sz[i];

	printf("%d",*max_element(sz+4,sz+1+tot));
	while(1);
	return 0;
}
