#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[200020];
int c[200020];
int s[80][160][160];
int t,n,d,m,b,f;
long long z;
struct P
{
	int x,y,z;
}p[100020];
bool operator<(const P&a,const P&b)
{
	return a.x<b.x;
}
void R(int x,int y)
{
	for(;x<=m;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int _=0;
	for(;x>0;x-=x&-x)
		_+=c[x];
	return _;
}
void work1()
{
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	b=0;
	for(int i=0;i<n;i++)
	{
		while(a[i]-a[b]>d)
			b++;
		z+=i-b;
	}
	printf("%lld\n",z);
}
void work2()
{
	m*=2;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		p[i].x=x-y,p[i].y=x+y;
	}
	sort(p,p+n);
	b=f=0;
	for(int i=0;i<n;i++)
	{
		while(p[i].x-p[b].x>d)
			R(p[b++].y,-1);
		while(f<n&&p[f].x-p[i].x<=d)
			R(p[f++].y,1);
		z+=G(min(p[i].y+d,m))-G(p[i].y-d-1);
	}
	printf("%lld\n",z-n>>1);
}
void work3()
{
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d %d",&p[i].z,&x,&y);
		p[i].x=x-y+m+1,p[i].y=x+y;
		s[p[i].z][p[i].x][p[i].y]++;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=2*m;j++)
			for(int k=1;k<=2*m;k++)
				s[i][j][k]+=s[i][j-1][k]+s[i][j][k-1]-s[i][j-1][k-1];
	for(int i=0;i<n;i++)
		for(int j=max(p[i].z-d,1);j<=min(p[i].z+d,m);j++)
		{
			int x1,y1,x2,y2,dd=d-abs(p[i].z-j);
			x1=max(p[i].x-dd,1),x2=min(p[i].x+dd,2*m);
			y1=max(p[i].y-dd,1),y2=min(p[i].y+dd,2*m);
			z+=s[j][x2][y2]-s[j][x1-1][y2]-s[j][x2][y1-1]+s[j][x1-1][y1-1];
		}
	printf("%lld\n",z-n>>1);
}
int main()
{
	scanf("%d %d %d %d",&t,&n,&d,&m);
	if(t==1)
		work1();
	else if(t==2)
		work2();
	else
		work3();
	return 0;
}
