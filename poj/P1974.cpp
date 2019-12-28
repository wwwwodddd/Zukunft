#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct P
{
	int x,y;
}p[200020];
int v[200020];
int n,m,l,ans;
bool operator<(const P&a,const P&b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
int cal(int x)
{
	return x>1;
}
void work()
{
	int lst=0;
	memset(v,0,sizeof v);
	for(int i=0;i<l;i++)
	{
		ans+=cal(p[i].y-lst-1);
		lst=p[i].y;
		if(i==l-1||p[i].x!=p[i+1].x)
		{
			ans+=cal(m-p[i].y);
			lst=0;
		}
		v[p[i].x]=1;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
			ans+=cal(m);
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d %d",&n,&m,&l);
		for(int i=0;i<l;i++)
			scanf("%d %d",&p[i].x,&p[i].y);
		sort(p,p+l);
		ans=0;
		work();
		swap(n,m);
		for(int i=0;i<l;i++)
			swap(p[i].x,p[i].y);
		sort(p,p+l);
		work();
		printf("%d\n",ans);
	}
	return 0;
}
