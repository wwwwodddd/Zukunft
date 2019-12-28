#include<iostream>
#include<algorithm>
using namespace std;
struct P{int x,y;}p[10006];
bool cmp(struct P a,struct P b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
int t,i,n;
double x,y;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		x=p[0].x+p[n-1].x;
		y=p[0].y+p[n-1].y;
		for(i=0;i<n/2;i++)
			if(x!=p[i].x+p[n-1-i].x||y!=p[i].y+p[n-1-i].y)
				break;
		printf("%s\n",i==n/2?"yes":"no");
	}
	return 0;
}