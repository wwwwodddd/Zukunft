#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
struct L{int u,l;}l[1010];
int c[1010],z[1010],n,m,xa,ya,xb,yb,x,y,mx,i;
using namespace std;
bool cmp(L a,L b)
{
	return b.u>a.u;
}
bool left(int m)
{
	return (l[m].u-l[m].l)*(y-yb)>(ya-yb)*(x-l[m].l);
}
void solve()
{
	int l=0,r=n;
	while(l<r)
		if(left((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	c[l]++;
}
int main()
{
	while(scanf("%d%d%d%d%d%d",&n,&m,&xa,&ya,&xb,&yb)+1,n)
	{
		memset(c,0,sizeof(c));
		memset(z,0,sizeof(z));
		for(i=0;i<n;i++)
			scanf("%d%d",&l[i].u,&l[i].l);
		sort(l,l+n,cmp);
		l[n].u=l[n].l=xb;
		while(m--)
		{
			scanf("%d%d",&x,&y);
			solve();
		}
		for(i=0;i<=n;i++)
		{
			mx=max(mx,c[i]);
			z[c[i]]++;
		}
		printf("Box\n");
		for(int i=1;i<=mx;i++)
			if(z[i])
				printf("%d: %d\n",i,z[i]);
	}
}