#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct P{
	int x,y,z;
	bool operator<(const P&a)const{
		return x>a.x||x==a.x&&y<a.y;
	}
}p[50020];
int dis(const P&a,const P&b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
struct E{
	int x,y,z;
	bool operator<(const E&a)const{
		return z<a.z;
	}
}e[200020];
int a[50020];
int f[50020];
int w[50020];
int l[50020];
int r[50020];
int z[50020];
int c[100020];
int n,m,ee,L,R;
long long ans;
long long gcd(long long x,long long y)
{
	return y?gcd(y,x%y):x;
}
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
int get(int x,int y)
{
	if(!x||!y)
		return x|y;
	return w[x]<w[y]?x:y;	
}
void work()
{
	sort(p,p+m);
	for(int i=0;i<m;i++)
		w[i]=p[i].x-p[i].y;
	for(int i=0;i<m;i++)
	{
		int _=0;
		for(int j=p[i].x+p[i].y;j;j-=j&-j)
			_=get(_,c[j]);
		if(_)
			e[ee++]=(E){p[i].z,p[_].z,dis(p[i],p[_])};
		for(int j=p[i].x+p[i].y;j<=2*n;j+=j&-j)
			c[j]=get(c[j],i);
	}
	memset(c,0,sizeof c);
}
vector<int>v[50020];
void ud(int x,int y)
{
	x=a[x];
	ans-=(long long)c[x]*c[x];
	c[x]+=y;
	ans+=(long long)c[x]*c[x];
}
void dfs(int x,int y)
{
	for(int i=L;i<l[x];i++)
		ud(i,-1);
	for(int i=r[x]+1;i<=R;i++)
		ud(i,-1);
	for(int i=l[x];i<L;i++)
		ud(i,1);
	for(int i=R+1;i<=r[x];i++)
		ud(i,1);
	L=l[x],R=r[x];
	z[x]=ans;
	fe(i,v[x])
		if(*i!=y)
			dfs(*i,x);
}
int main()
{
	scanf("%d %d",&n,&m),m++;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<m;i++)
		scanf("%d %d",l+i,r+i),f[i]=i;
	L=l[0]=1;
	for(int i=0;i<m;i++)
		p[i]=(P){l[i],r[i],i};
	work();
	for(int i=0;i<m;i++)
		p[i]=(P){l[i],n-r[i]+1,i};
	work();
	for(int i=0;i<m;i++)
		p[i]=(P){n-l[i]+1,r[i],i};
	work();
	for(int i=0;i<m;i++)
		p[i]=(P){n-l[i]+1,n-r[i]+1,i};
	work();
	sort(e,e+ee);
	for(int i=0;i<ee;i++)
	{
		int fx=F(e[i].x),fy=F(e[i].y);
		if(fx!=fy)
		{
			f[fx]=fy;
			v[e[i].x].push_back(e[i].y);
			v[e[i].y].push_back(e[i].x);
		}
	}
	dfs(0,-1);
	for(int i=1;i<m;i++)
	{
		long long u=r[i]-l[i]+1,fm=u*(u-1),fz=z[i]-u;
		long long g=gcd(fm,fz);	
		printf("%lld/%lld\n",fz/g,fm/g);
	}
	return 0;
}
