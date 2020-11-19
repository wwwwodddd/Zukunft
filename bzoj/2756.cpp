#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,s,t;
int h[1620],tot;
int v[1620];
long long b[50][50];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
long long kk,ans;
long long mh;
long long sum[2];
struct N
{
	int x,y;
	long long z;
}a[200020];
void add(int x,int y,long long z)
{
	tot++;
	a[tot].x=h[x];
	a[tot].y=y;
	a[tot].z=z;
	h[x]=tot;

	tot++;
	a[tot].x=h[y];
	a[tot].y=x;
	a[tot].z=0;
	h[y]=tot;
}
int bfs()
{
	queue<int>q;
	memset(v,0,sizeof v);
	q.push(s);
	v[s]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=a[i].x)
			if(a[i].z&&!v[a[i].y])
			{
				v[a[i].y]=v[u]+1;
				if(a[i].y==t)
					return 1;
				q.push(a[i].y);
			}
	}
	return 0;
}
long long dfs(int x,long long y)
{
	if(x==t)
		return y;
	long long u=0;
	for(int i=h[x];i;i=a[i].x)
		if(u<y&&a[i].z&&v[a[i].y]==v[x]+1)
		{
			long long k=dfs(a[i].y,min(a[i].z,y-u));
			if(!k)
				v[a[i].y]=0;
			u+=k;
			a[i].z-=k;
			a[i^1].z+=k;
		}
	return u;
}
int ok(long long x)
{
	memset(h,0,sizeof h);
	tot=1;
	s=n*m,t=s+1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(i+j&1)
			{
				add(s,i*m+j,x-b[i][j]);
				for(int k=0;k<4;k++)
				{
					int x=i+dx[k],y=j+dy[k];
					if(x>=0&&y>=0&&x<n&&y<m)
						add(i*m+j,x*m+y,0xffffffffffLL);
				}
			}
			else
				add(i*m+j,t,x-b[i][j]);
	ans=0;
	while(bfs())
		while(kk=dfs(s,0xffffffffffLL))
			ans+=kk;
	return ans*2==sum[0]+sum[1]+(long long)(x-mh)*n*m;
}
void work()
{
	scanf("%d %d",&n,&m);
	sum[0]=sum[1]=0;
	mh=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> b[i][j] ,mh=max(mh,b[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			sum[i+j&1]+=mh-b[i][j];
	if(n&m&1)
	{
		if(sum[0]<=sum[1]&&ok(mh+sum[1]-sum[0]))
			cout << ans << endl;
		else
			puts("-1");
	}
	else
	{
		long long l=mh,r=10000000000LL,mid;
		while(l<r)
		{
			mid=l+r>>1;
			if(ok(mid))
				r=mid;
			else
				l=mid+1;
		}
		ok(l);
		cout << ans << endl;
	}
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
		work();
	return 0;
}
