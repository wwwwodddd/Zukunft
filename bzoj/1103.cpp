#include<stdio.h>
#include<iostream>
using namespace std;
int h[1000020];
int a[1000020][2];
int tot,cnt;
int l[1000020];
int r[1000020];
int c[1000020];
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void dfs(int x,int y)
{
	int i;
	l[x]=++cnt;
	for(i=h[x];i;i=a[i][0])
		if(a[i][1]!=y)
			dfs(a[i][1],x);
	r[x]=++cnt;
}
void R(int x,int y)
{
	int i;
	for(i=x;i<=cnt;i+=i&-i)
		c[i]+=y;
}
int G(int x)
{
	int i,re=0;
	for(i=x;i;i-=i&-i)
		re+=c[i];
	return re;
}
char o[5];
int main()
{
	int i,x,y,n,m;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(i=2;i<=n;i++)
	{
		R(l[i],1);
		R(r[i],-1);
	}
	scanf("%d",&m);
	for(i=1;i<n+m;i++)
	{
		scanf("%s",o);
		if(o[0]=='W')
		{
			scanf("%d",&x);
			printf("%d\n",G(l[x]));
		}
		else
		{
			scanf("%d %d",&x,&y);
			R(max(l[x],l[y]),-1);
			R(min(r[x],r[y]),1);
		}
	}
	return 0;
}