//DNF
/*
some serious problems.
*/
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
int n,m,mo=14121413;
struct N
{
	int a[12],b[12],v;
	N()
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
	}
	void scan()
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		for(int i=0;i<n;i++)
			scanf("%d",b+i);
		for(int i=0;i<n;i++)
			if(a[i]>b[i])
				swap(a[i],b[i]);
		v=1;
	}
	int nom()
	{
		if(!v)
			return 0;
		for(int i=0;i<n;i++)
			if(a[i]>=b[i])
				return 0;
		return 1;
	}
	int vol()
	{
		int _=v;
		for(int i=0;i<n;i++)
			_=(long long)_*(b[i]-a[i])%mo;
		return _;
	}
}s[500020],q,p;
int ss,sc;
N operator+(const N&a,const N&b)
{
	N _;
	if(a.v>0)
		_.v=-1;
	else
		_.v=1;
	for(int i=0;i<n;i++)
	{
		_.a[i]=max(a.a[i],b.a[i]);
		_.b[i]=min(a.b[i],b.b[i]);
	}
	return _;
}
bool operator==(const N&a,const N&b)
{
	for(int i=0;i<n;i++)
		if(a.a[i]!=b.a[i])
			return 0;
	for(int i=0;i<n;i++)
		if(a.b[i]!=b.b[i])
			return 0;
	return 1;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	while(~scanf("%d %d",&m,&n))
	{
		ss=sc=0;
		memset(s,0,sizeof s);
		for(int i=0;i<m;i++)
		{
			q.scan();
			s[sc++]=q;
			for(int j=0;j<ss;j++)
			{
				p=s[j]+q;
				if(p.nom())
				{
					if(p==q)
					{
						sc=ss;
						break;
					}
					s[sc++]=p;
				}
			}
			cerr << ss << endl;
			ss=sc;
		}
		int z=0;
		for(int i=0;i<ss;i++)
			z=(z+s[i].vol())%14121413;
		printf("%d\n",(z+mo)%mo);
	}
	return 0;
}
