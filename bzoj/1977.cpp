#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int>ii;
vector<ii>a[100020];
int f[100020][18];
int d[100020];
long long ans;
int n,m;
struct A
{
	int mx,mx2;
}g[100020][18];
A operator+(const A&a,const A&b)
{
	A re;
	re.mx=max(a.mx,b.mx);
	re.mx2=0xc0c0c0c0;
	if(a.mx!=re.mx)
		re.mx2=max(re.mx2,a.mx);
	if(b.mx!=re.mx)
		re.mx2=max(re.mx2,b.mx);
	if(a.mx2!=re.mx)
		re.mx2=max(re.mx2,a.mx2);
	if(b.mx2!=re.mx)
		re.mx2=max(re.mx2,b.mx2);
	return re;
}
struct E
{
	int x,y,z;
	void scan()
	{
		scanf("%d %d %d",&x,&y,&z);
	}
}e[300020];
bool operator<(const E&a,const E&b)
{
	return a.z<b.z;
}
namespace MST
{
	int f[100020];
	int F(int x)
	{
		return f[x]!=x?f[x]=F(f[x]):x;
	}
	void work()
	{
		fo(i,n)
			f[i]=i;
		fr(i,m)
			if(F(e[i].x)!=F(e[i].y))
			{
				a[e[i].x].push_back(ii(e[i].y,e[i].z));
				a[e[i].y].push_back(ii(e[i].x,e[i].z));
				f[F(e[i].x)]=F(e[i].y);
				ans+=e[i].z;
			}
	}
}
void bfs(int x)
{
	queue<int>q;
	q.push(x);
	while(q.size())
	{
		x=q.front();
		q.pop();
		for(int i=1;i<18;i++)
		{
			f[x][i]=f[f[x][i-1]][i-1];
			g[x][i]=g[x][i-1]+g[f[x][i-1]][i-1];
		}
		fe(i,a[x])
			if(i->X!=f[x][0])
			{
				d[i->X]=d[x]+1;
				f[i->X][0]=x;
				g[i->X][0].mx=i->Y;
				q.push(i->X);
			}
	}	
}
A LCA(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	int nd=d[x]-d[y];
	A re={0xc0c0c0c0,0xc0c0c0c0};
	for(int i=0;i<18;i++)
		if(nd>>i&1)
		{
			re=re+g[x][i];
			x=f[x][i];
		}
	if(x==y)
		return re;
	for(int i=0;i<18;i++)
		if(f[x][i]!=f[y][i])
		{
			re=re+g[x][i]+g[y][i];
			x=f[x][i];
			y=f[y][i];
		}
	return re+g[x][0]+g[y][0];
}
int main()
{
	scanf("%d %d",&n,&m);
	fr(i,m)
		e[i].scan();
	sort(e,e+m);
	MST::work();
	memset(g,0xc0,sizeof g);
	d[1]=1;
	bfs(1);
	int dd=0x3f3f3f3f;
	fr(i,m)
	{
		A u=LCA(e[i].x,e[i].y);
		if(u.mx!=e[i].z)
			dd=min(dd,e[i].z-u.mx);
		else
			dd=min(dd,e[i].z-u.mx2);
	}
	cout << ans+dd;
	return 0;
}
