#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
vector<int>v[10020];
int l[10020],lc;
int r[10020];
int a[10020];
typedef pair<int,int> ii;
ii p[105][105],ans;
int lim,bn,n,q;
int Q(int x)
{
	return lower_bound(l,l+lc,x)-l;
}
int C(int l,int r,int x)
{
	return lower_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
}
int main()
{
	freopen("c.in","r",stdin);
	int t,x,y;
	scanf("%d %d",&n,&t);
	lim=(int)sqrt((double)n);
	bn=n/lim;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),l[lc++]=a[i];
	sort(l,l+lc);
	lc=unique(l,l+lc)-l;
	for(int i=1;i<=n;i++)
	{
		r[i]=Q(a[i]);
		v[r[i]].push_back(i);
	}
	for(int i=0;i<bn;i++)
	{
		for(int j=i;j<bn;j++)
		{
			if(j>i)
				p[i][j]=p[i][j-1];
			for(int k=j*lim;k<(j+1)*lim;k++)
				p[i][j]=max(p[i][j],ii(C(i*lim,(j+1)*lim,r[k]),-r[k]));
		}
	}
	int o=0;
	for(;t--;)
	{
		scanf("%d %d",&x,&y);
		if(o)
		{
			x=(x+l[-ans.second]-1)%n+1;
			y=(y+l[-ans.second]-1)%n+1;
		}
		o=1;
		if(x>y)
			swap(x,y);
		int bl=(x+lim-2)/lim;
		int br=y/lim-1;
		if(br<bl)
		{
			ans=ii(0,0);
			for(int i=x;i<=y;i++)
				ans=max(ans,ii(C(x,y+1,r[i]),-r[i]));
		}
		else
		{
			ans=p[bl][br];
			for(int i=x;i<=bl*lim;i++)
				ans=max(ans,ii(C(x,y+1,r[i]),-r[i]));
			for(int i=br*lim+1;i<=y;i++)
				ans=max(ans,ii(C(x,y+1,r[i]),-r[i]));
		}
		printf("%d\n",l[-ans.second]);
	}
	while(1);
}
