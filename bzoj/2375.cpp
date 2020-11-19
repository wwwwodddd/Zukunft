#include<stdio.h>
#include<iostream>
using namespace std;
int f[1000020];
int s[1000020],ss;
int c[1000020];
int i,j,n,m,p,q,x,y,cnt;
int F(int x)
{
	int i;
	ss=0;
	while(f[x]!=x)
	{
		s[ss++]=x;
		x=f[x];
	}
	for(i=0;i<ss;i++)
		f[s[i]]=x;
	return x;
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&p,&q);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=m;i>0;i--)
	{
		x=(i*p+q)%n+1;
		y=(i*q+p)%n+1;
		if(x>y)
			swap(x,y);
		for(j=f[x];j<=y;j=F(j))
		{
			c[j]=i;
			cnt++;
			f[j]=j+1;
		}
		if(cnt==n)
			break;
	}
	for(i=1;i<=n;i++)
		printf("%d\n",c[i]);
	return 0;
}