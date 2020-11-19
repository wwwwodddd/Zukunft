#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
int a[3000020][2],tot;
int h[3020];
int v[3020];
int lnk[3020];
int wa[220];
int wb[3020];
int l[220][3020];
int an,n,m;
int tim;
int ans;
namespace A
{
	int dfs(int x)
	{
		for(int i=h[x];i;i=a[i][0])
			if(v[a[i][1]]!=tim)
			{
				v[a[i][1]]=tim;
				if(lnk[a[i][1]]==0||dfs(lnk[a[i][1]]))
					return lnk[a[i][1]]=x,1;
			}
		return 0;
	}
	void solve()
	{
		int re=0;
		memset(v,0,sizeof v);
		memset(lnk,0,sizeof lnk);
		for(tim=1;tim<=n;tim++)
			if(wb[tim]&1)
				re+=dfs(tim);
		ans=max(ans,n-re);
	}
}
namespace B
{
	int cho,nc;
	int dfs(int x)
	{
		if(!l[cho][x])
			return 0;
		for(int i=h[x];i;i=a[i][0])
			if(v[a[i][1]]!=tim&&l[cho][a[i][1]])
			{
				v[a[i][1]]=tim;
				if(lnk[a[i][1]]==0||dfs(lnk[a[i][1]]))
					return lnk[a[i][1]]=x,1;
			}
		return 0;
	}
	void solve()
	{
		int re=0;
		for(cho=1;cho<=an;cho++)
		{
			memset(v,0,sizeof v);
			memset(lnk,0,sizeof lnk);
			nc=0;
			re=0;
			for(int i=1;i<=n;i++)
				if(l[cho][i])
					nc++;
			for(tim=1;tim<=n;tim++)
				if(wb[tim]&1)
					re+=dfs(tim);
			ans=max(ans,nc-re+1);
		}
	}
}
namespace C
{
	int cho1,cho2,nc;
	int dfs(int x)
	{
		if(!l[cho1][x])
			return 0;
		if(!l[cho2][x])
			return 0;
		for(int i=h[x];i;i=a[i][0])
			if(v[a[i][1]]!=tim&&l[cho1][a[i][1]]&&l[cho2][a[i][1]])
			{
				v[a[i][1]]=tim;
				if(lnk[a[i][1]]==0||dfs(lnk[a[i][1]]))
					return lnk[a[i][1]]=x,1;
			}
		return 0;
	}
	void solve()
	{
		int re=0;
		for(cho1=1;cho1<=an;cho1++)
			for(cho2=cho1+1;cho2<=an;cho2++)
			if((wa[cho1]^wa[cho2])%2==1)
			{
				memset(v,0,sizeof v);
				memset(lnk,0,sizeof lnk);
				nc=0;
				re=0;
				for(int i=1;i<=n;i++)
					if(l[cho1][i]&&l[cho2][i])
						nc++;
				for(tim=1;tim<=n;tim++)
					if(wb[tim]&1)
						re+=dfs(tim);
				ans=max(ans,nc-re+2);
			}
	}
}
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
int cot(int x)
{
	int re=0;
	for(;x;x>>=1)
		re^=x&1;
	return re;
}
int main()
{
	scanf("%d %d %d",&an,&n,&m);
	for(int i=1;i<=an;i++)
		scanf("%d",wa+i);
	for(int i=1;i<=n;i++)
		scanf("%d",wb+i);
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&x,&y);
		l[x][y]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(((wb[i]^wb[j])%2==0)||cot(wb[i]|wb[j])==1)
				;
			else
				add(i,j);
		}
	A::solve();
	B::solve();
	C::solve();
	printf("%d\n",ans);
}
