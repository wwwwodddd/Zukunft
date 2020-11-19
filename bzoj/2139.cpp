#include<stdio.h>
#include<iostream>
#include<algorithm>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
int f[1000020];
ii a[1000020],b[1000020],c[1000020];
int i,x,y,z,n,p=32767,ans;
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	f[F(x)]=F(y);
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d %d %d %d",&a[0].X,&a[1].X,&x,&y,&z);
	for(i=0;i<n;i++)
		a[i].Y=b[i].Y=i;
	for(i=2;i<n;i++)
		a[i].X=(a[i-1].X*x+a[i-2].X*y+z)%p;
	scanf("%d %d %d %d %d",&b[0].X,&b[1].X,&x,&y,&z);
	for(i=2;i<n;i++)
		b[i].X=(b[i-1].X*x+b[i-2].X*y+z)%p;
	for(i=0;i<n;i++)
		f[i]=i;
	sort(a,a+n);
	sort(b,b+n);
	for(i=0;i<n;i++)
	{
		U(a[i].Y,b[i].Y);
		ans=max(ans,a[i].X*a[i].X-b[i].X*b[i].X);
	}
	for(i=0;i<n-1;i++)
	{
		c[i].X=a[i+1].X*a[i+1].X-b[i].X*b[i].X;
		c[i].Y=i;
	}
	sort(c,c+n-1);
	for(i=0;i<n-1;i++)
	{
		if(F(a[c[i].Y+1].Y)!=F(b[c[i].Y].Y))
		{
			ans=max(ans,c[i].X);
			U(a[c[i].Y].Y,b[c[i].Y+1].Y);
		}
	}
	printf("%d",ans);
	return 0;
}