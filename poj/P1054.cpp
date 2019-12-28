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
bool v[5020][5020];
struct P
{
	int x,y;
}p[5020];
bool operator<(const P&a,const P&b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;	
}
int n,m,l;
int in(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;	
}
int ans;
int main()
{
	scanf("%d %d %d",&n,&m,&l);
	fr(i,l)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
		v[p[i].x][p[i].y]=1;
	}
	fr(i,l)
		fr(j,i)
		{
			int dx=p[i].x-p[j].x;
			int dy=p[i].y-p[j].y;
			int cx=p[i].x;
			int cy=p[i].y;
			if(in(p[j].x-dx,p[j].y-dy))
				if(v[p[j].x-dx][p[j].y-dy])
					break;
			int cnt=1;
			while(in(cx,cy))
			{
				if(!v[cx][cy])
					break;
				cx+=dx;
				cy+=dy;
				cnt++;
			}
			if(!in(cx,cy))
				ans=max(ans,cnt);
		}
	if(ans<3)
		ans=0;
	printf("%d",ans);
	while(1);
}
