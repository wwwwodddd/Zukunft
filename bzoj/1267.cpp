#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int a[100020][3],tot=1;
int h[50020],z[50020],v[50020];
int d[50020],s[50020],u[50020];
int f[50020],fc,g[50020],gc;
int sn[50020],cn;
int n,m,sct,sm,mn,mx;
void F(int x,int y)
{
	s[x]=1;
	u[x]=0;
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]]&&a[i][1]!=y)
		{
			F(a[i][1],x);
			s[x]+=s[a[i][1]];
			u[x]=max(u[x],s[a[i][1]]);
		}
	u[x]=max(u[x],sm-s[x]);
	if(u[x]<mn)
		mn=u[sct=x];
}
inline bool cmp(const int&x,const int&y)
{
	return s[x]<s[y];
}
inline void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void mk(int x,int y)
{
	s[x]=1;
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]]&&a[i][1]!=y)
		{
			d[a[i][1]]=d[x]+a[i][2];
			mx=max(mx,d[a[i][1]]);
			mk(a[i][1],x);
			s[x]+=s[a[i][1]];
		}
}
void ad(int x,int y)
{
	g[gc++]=d[x];
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]]&&a[i][1]!=y)
			ad(a[i][1],x);
}
inline int push(int x)
{
	if(q.size()<m)
		return q.push(x),0;
	else if(x>q.top())
		return q.pop(),q.push(x),0;
	return 1;
}
void work(int x)
{
	v[x]=1;
	d[x]=0;
	mx=0;
	mk(x,0);
	if(q.size()==m&&mx*2<=q.top())
		return;
	cn=0;
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]])
			sn[cn++]=a[i][1];
	sort(sn,sn+cn,cmp);
	fc=0;
	f[fc++]=0;
	for(int i=0;i<cn;i++)
	{
		gc=0;
		ad(sn[i],x);
		sort(g,g+gc);
		for(int i=gc-1,j;~i;i--)
		{
			for(j=fc-1;~j;j--)
				if(push(g[i]+f[j]))
					break;
			if(j==fc-1)
				break;
		}
		for(int i=0;i<gc;i++)
			f[fc++]=g[i];
		inplace_merge(f,f+fc-gc,f+fc);
	}
	for(int i=h[x];i;i=a[i][0])
		if(!v[a[i][1]])
		{
			sm=s[a[i][1]];
			mn=0x3f3f3f3f;
			F(a[i][1],x);
			work(sct);
		}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	sm=n;
	mn=0x3f3f3f3f;
	F(1,0);
	work(sct);
	for(int i=m-1;~i;i--)
	{
		z[i]=q.top();
		q.pop();
	}
	for(int i=0;i<m;i++)
		printf("%d\n",z[i]);
	return 0;
}
