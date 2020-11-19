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
typedef pair<int,int> ii;
ii p[10020];
int d[10020];
queue<int>q;
int h,n;
int main()
{
	scanf("%d %d",&h,&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&p[i].X,&p[i].Y);
	sort(p,p+n);
	memset(d,0,sizeof d);
	for(int i=0;i<n;i++)
		if(p[i].Y<=1000)
			d[i]=1,q.push(i);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		if(p[u].Y>=h-1000)
		{
			printf("%d\n",d[u]);
			return 0;
		}
		int lo=lower_bound(p,p+n,ii(p[u].X-1000,p[u].Y-1000))-p;
		int hi=upper_bound(p,p+n,ii(p[u].X+1000,p[u].Y+1000))-p;
		for(int i=lo;i<hi;i++)
			if(!d[i]&&(p[i].X-p[u].X)*(p[i].X-p[u].X)+(p[i].Y-p[u].Y)*(p[i].Y-p[u].Y)<=1000000)
				d[i]=d[u]+1,q.push(i);
	}
	return 0;
}
