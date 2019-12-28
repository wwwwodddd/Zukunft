#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,m,x,y,z;
int a[200020][3];
int t[1000000][3];
int h[100020],tot;
int s[100020];
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void clr(int m)
{
	t[m][0]=t[m][1]=t[m][2]=0;
}
void ins(int x)
{
	int c,p=0;
	for(int i=30;i>=0;i--)
	{
		c=(x>>i)&1;
		if(t[p][c]==0)
			clr(t[p][c]=++m);
		p=t[p][c];
	}
	t[p][2]=x;
}
int fnd(int x)
{
	int c,p=0;
	for(int i=30;i>=0;i--)
	{
		c=(x>>i)&1;
		if(t[p][1-c]==0)
			p=t[p][c];
		else
			p=t[p][1-c];
	}
	return t[p][2];
}
void dfs(int x,int y,int z)
{
	s[x]=y;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=z)
			dfs(a[i][1],y^a[i][2],x);
}
void work()
{
	memset(s,0,sizeof(s));
	dfs(1,0,0);
	int ans=0;
	clr(m=0);
	for(int i=1;i<=n;i++)
	{
		if(i>1)
			ans=max(ans,fnd(s[i])^s[i]);
		ins(s[i]);
	}
	printf("%d\n",ans);
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		tot=0;
		memset(h,0,sizeof(h));
		memset(t,0,sizeof(t));
		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			x++;
			y++;
			add(x,y,z);
			add(y,x,z);
		}
		work();
	}
	return 0;
}