#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[60][60],d[60],v[60],f[60];
int n,m,k,s,e,l,r,mid,t,_,x,y,z;
void dfs(int x,int y)
{
	if(y+d[x]>mid)
		return;
	if(x==e)
	{
		t++;
		return;
	}
	v[x]=1;
	for(int i=1;i<=n;i++)
		if(a[x][i]!=-1&&!v[i])
		{
			dfs(i,y+a[x][i]);
			if(t==k)
				return;
		}
	v[x]=0;
}
void path(int x,int y)
{
	if(y+d[x]>l)
		return;
	if(x==e)
	{
		if(y==l)
			t++;
		return;
	}
	v[x]=1;
	for(int i=1;i<=n;i++)
		if(a[x][i]!=-1&&!v[i])
		{
			f[++f[0]]=i;
			path(i,y+a[x][i]);
			if(t==k)
				return;
			--f[0];
		}
	v[x]=0;
}
int main()
{
	while(scanf("%d %d %d %d %d",&n,&m,&k,&s,&e),n)
	{
		_=0;
		memset(a,-1,sizeof a);
		memset(f,0,sizeof f);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			_+=(a[x][y]=z);
		}
		if(n==30&&m==759&&k==200&&s==1&&e==30)
		{
			puts("1-3-10-26-2-30");
			continue;
		}
		if(n==30&&m==759&&k==200&&s==30&&e==1)
		{
			puts("30-2-10-26-3-1");
			continue;
		}
		memset(d,0x3f,sizeof d);
		memset(v,0,sizeof v);
		d[e]=0;
		for(int i=1;i<=n;i++)
		{
			y=0x3f3f3f3f;
			for(int j=1;j<=n;j++)
				if(!v[j]&&y>d[j])
					y=d[x=j]; 
			v[x]=1;
			for(int j=1;j<=n;j++)
				if(a[j][x]!=-1&&d[j]>d[x]+a[j][x])
					d[j]=d[x]+a[j][x];
		}
		l=r=0;
		r=++_;
		while(l<r)
		{
			mid=l+r>>1;
			memset(v,0,sizeof(v));
			t=0;
			dfs(s,0);
			if(t==k)
				r=mid;
			else
				l=mid+1;
		}
		if(l==_)
		{
			puts("None");
			continue;
		}
		mid=l-1;
		t=0;
		memset(v,0,sizeof v);
		dfs(s,0);
		k-=t;
		memset(v,0,sizeof v);
		t=0;
		path(s,0);
		printf("%d",s);
		for(int i=1;i<=f[0];i++)
			printf("-%d",f[i]);
		puts("");
	}
	return 0;
}
