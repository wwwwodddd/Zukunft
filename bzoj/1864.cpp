#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
char s[10020];
int f[10020],p;
int g[10020];
int l[10020],r[10020];
int len;
void dfs()
{
	int now=p++;
	if(s[now]=='1')
	{
		l[now]=p;
		dfs();
	}
	else if(s[now]=='2')
	{
		l[now]=p;
		dfs();
		r[now]=p;
		dfs();
	}
	return;
}
int main()
{
	int i;
	scanf("%s",s+1);
	len=strlen(s+1);
	p=1;
	dfs();
	for(i=len;i>0;i--)
	{
		if(s[i]=='0')
		{
			f[i]=1;
			g[i]=0;
		}
		else if(s[i]=='1')
		{
			f[i]=g[l[i]]+1;
			g[i]=max(g[l[i]],f[l[i]]);
		}
		else
		{
			f[i]=g[l[i]]+g[r[i]]+1;
			g[i]=max(g[l[i]]+f[r[i]],f[l[i]]+g[r[i]]);
		}
	}
	printf("%d ",max(f[1],g[1]));
	for(i=len;i>0;i--)
	{
		if(s[i]=='0')
		{
			f[i]=1;
			g[i]=0;
		}
		else if(s[i]=='1')
		{
			f[i]=g[l[i]]+1;
			g[i]=min(g[l[i]],f[l[i]]);
		}
		else
		{
			f[i]=g[l[i]]+g[r[i]]+1;
			g[i]=min(g[l[i]]+f[r[i]],f[l[i]]+g[r[i]]);
		}
	}
	printf("%d",min(f[1],g[1]));
	return 0;
}