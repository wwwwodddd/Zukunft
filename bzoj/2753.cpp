#include<stdio.h>
#include<string.h>
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
int mn[100020];
int v[100020];
int f[100020];
int g[100020];
int h[100020],tot;
int a[2000020][2];
int n,m;
struct E
{
	int x,y,z;
}e[1000020];
bool operator<(const E&a,const E&b)
{
	return a.z<b.z;	
}
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	x=F(x),y=F(y);
	mn[x]=min(mn[x],mn[y]);
	f[y]=x;
}
void dfs(int x,int y)
{
	v[x]=1;
	for(int i=h[x];i;i=a[i][0])
		if(a[i][1]!=y&&!v[a[i][1]])
			dfs(a[i][1],x);
}
long long ans;
int main()
{
	memset(mn,0x7f,sizeof mn);
	int x,y,z;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",g+i);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		e[i]=(E){x,y,z};
		if(g[x]>=g[y])
			add(x,y);
		if(g[y]>=g[x])
			add(y,x);
	}
	dfs(1,0);
	int j=0;
	for(int i=0;i<m;i++)
		if(v[e[i].x]&&v[e[i].y])
			e[j++]=e[i];
	m=j;
	sort(e,e+m);
	for(int i=0;i<m;i++)
	{
		if(g[e[i].x]==g[e[i].y])
		{
			if(F(e[i].x)!=F(e[i].y)&&e[i].z<max(mn[F(e[i].x)],mn[F(e[i].y)]))
			{
				U(e[i].x,e[i].y);
				ans+=e[i].z;
			}
		}
		else if(g[e[i].x]>g[e[i].y])
			mn[F(e[i].y)]=min(mn[F(e[i].y)],e[i].z);
		else
			mn[F(e[i].x)]=min(mn[F(e[i].x)],e[i].z);
	}
	for(int i=1;i<=n;i++)
		*v+=v[i];
	for(int i=1;i<=n;i++)
		if(v[i]&&F(i)==i&&F(1)!=i)
			ans+=mn[i];
	cout<<*v<<' '<<ans;
	return 0;
}
