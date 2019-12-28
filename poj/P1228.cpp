#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
struct P
{
	int x,y;
	bool operator<(const P&a)const
	{
		return y<a.y||y==a.y&&x<a.x;
	};
}p[1020],s[1020];
int ss,csc,i,j,n,l;
int xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int dis(P a,P b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
void ch()
{
	sort(p,p+n);
	s[0]=p[0];
	s[1]=p[1];
	ss=1;
	for(i=2;i<n;i++)
	{
		while(ss>0&&xm(s[ss-1],s[ss],p[i])<0)
			ss--;
		s[++ss]=p[i];
	}
	l=ss;
	for(i=n-2;i>=0;i--)
	{
		while(ss>l&&xm(s[ss-1],s[ss],p[i])<0)
			ss--;
		s[++ss]=p[i];
	}
	l=ss;
}
int check()
{
	if(ss<6)
		return 0;
	if(ss==1)
		return 0;
	int cnt;
	for(i=0;i<ss;i++)
	{
		cnt=0;
		for(j=0;j<ss;j++)
			if(xm(s[i],s[i+1],s[j])==0)
				cnt++;
		if(cnt<3)
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d %d",&p[i].x,&p[i].y);
		ch();
		puts(check()?"YES":"NO");
	}
	return 0;
}