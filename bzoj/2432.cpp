//DNF
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
long long f[1000020];
long long g[1000020];
long long a[1000020];
long long ex[1000020];
long long n,k,p,m,s;
long long i,j,l,ans,a0,a1,la0,la1;
long long pos,st;
void mul(long long a[2][2],long long b[2][2],long long c[2][2])
{
	int i,j,k;
	long long re[2][2];
	memset(re,0,sizeof(re));
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
				re[i][j]=(re[i][j]+b[i][k]*c[k][j])%p;
	memcpy(a,re,sizeof(re));
	return;
}
void pw(long long x[2][2],long long y,long long z[2][2])
{
	long long re[2][2];
	memset(re,0,sizeof(re));
	re[0][0]=re[1][1]=1;
	while(y)
	{
		if(y&1)
			mul(re,re,x);
		y>>=1;
		mul(x,x,x);
	}
	memcpy(z,re,sizeof(re));
}
long long F(long long x)
{
	long long a[2][2];
	long long b[2][2];
	a[0][0]=a[1][0]=a[1][1]=0;
	a[0][1]=1;
	b[1][0]=b[0][1]=b[1][1]=1;
	b[0][0]=0;
	pw(b,x,b);
	mul(a,a,b);
	return a[0][0];
}
void gcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	gcd(b,a%b,y,x);
	y-=(a/b)*x;
}
long long EX(long long x)
{
	long long i;
	if(!ex[x])
		gcd(x,k,ex[x],i);
	ex[x]=(ex[x]+k)%k;
	return ex[x];
}
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	p=100000;
	k=101;
	n=10000;
	m=p*k;
//	scanf("%lld %lld %lld",&n,&k,&p);
	f[1]=1;
	g[1]=1;
	for(i=2;i<1000020;i++)
	{
		f[i]=(f[i-1]+f[i-2])%m;
		j=EX(f[i]%k);
		if(!g[j])
		{
			g[j]=i;
		}
		if(f[i]==1&&f[i-1]==0)
			break;
	}
	a[1]=a[2]=1;
	for(i=3;i<=n;i++)
	{
		a[i]=(a[i-1]+a[i-2])%m;
		if(a[i]%k==1)
		{
			a[i]--;
			break;
		}
	}
	if(i>n)
	{
		printf("%d",a[n]);
		return 0;
	}
	a0=a[i-1];
	a1=a[i];
	pos=i;
	while(pos+g[a0%k]<=n)
	{
		st=a0%k;
		if(g[st]==0)
			break;
		pos+=g[st];
		la0=a0;
		la1=a1;
		a0=(la1*f[g[st]]+la0*f[g[st]-1])%m;
		a1=(la1*f[g[st]+1]+la0*f[g[st]]-1)%m;
//		printf("%8lld %8lld\n",a0%p,a1%p);
	}
	k=n-pos;
	ans=(a0%p*F(k)+a1%p*F(k+1))%p;
	printf("%d",ans);
	return 0;
}