#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int> ii;
vector<ii>t[100020];
int l[20020][2];
int a[20020][2];
int w[100020];
int v[100020],vi;
int ans[20020];
int s[100020];
int g[100020];
int ed[50020];
int cnt[100020];
int n,m,ss,tt,b,f;
int q[100020];
int F(int x,int y)
{
	fe(i,t[x])
		if(i->X==y)
			return i->Y;
	return 0;	
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<2;j++)
		{
			scanf("%d",l[i]+j);
			a[i][j]=ss;
			for(int k=0;k<l[i][j];k++)
				scanf("%d",s+ss+k);
			ss+=l[i][j];
		}
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d",&x);
		int p=0;
		for(int k=0;k<x;k++)
		{
			scanf("%d",&y);
			z=F(p,y);
			if(!z)
			{
				tt++;
				t[p].push_back(ii(y,tt));
				z=tt;
			}
			p=z;
		}
		w[p]++;
		ed[i]=p;
	}
	q[f++]=0;
	while(b<f)
	{
		int u=q[b++],v,z=0;
		fe(i,t[u])
		{
			v=g[u];
			while(u)
			{
				if(z=F(v,i->X))
					break;
				if(!v)
					break;
				v=g[v];
			}
			g[i->Y]=z;
			q[f++]=i->Y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		vi++;
		for(int j=0;j<2;j++)
		{
			int p=0,z;
			for(int k=0;k<l[i][j];k++)
			{
				z=0;
				while(!(z=F(p,s[a[i][j]+k]))&&p)
					p=g[p];
				p=z;
				while(v[z]!=vi)
				{
					v[z]=vi;
					ans[i]+=w[z];
					cnt[z]++;
					z=g[z];
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",cnt[ed[i]]);
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i],i<n?' ':'\n');
	return 0;
}
