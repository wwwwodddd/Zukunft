#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[200020][3];
int h[2020];
int v[2020];
int l[2020];
int n,m,i,j,k,x,y,tot;
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int dfs(int x)
{
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]])
		{
			v[a[i][1]]=1;
			if(l[a[i][1]]==-1||dfs(l[a[i][1]]))
			{
				l[a[i][1]]=x;
				return 1;
			}
		}
	return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	memset(l,-1,sizeof(l));
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		add(i,x);
		add(i,y);
	}
	for(i=0;i<n;i++)
	{
		memset(v,0,sizeof(v));
		if(!dfs(i))
			break;
	}
	printf("%d",i);
	return 0;
}