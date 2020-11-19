#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int N,n,m,p,q;
struct M
{
	long long a[220][220];
}a,b;
M operator *(const M &a,const M &b)
{
	M re;
	memset(&re,0,sizeof re);
	for(int i=0;i<N;i++)
		for(int k=0;k<N;k++)
			if(a.a[i][k])
				for(int j=0;j<N;j++)
				{
					re.a[i][j]=(re.a[i][j]+a.a[i][k]*b.a[k][j])%p;;
				}
	return re;
}
void mpw(int y)
{
	for(;y;y>>=1)
	{
		if(y&1)
			a=a*b;
		b=b*b;	
	}
}
long long pw(long long x,int y)
{
	long long re=1;
	for(;y;y>>=1)
	{
		if(y&1)
			re=re*x%p;
		x=x*x%p;
	}
	return re;
}
namespace B
{
	int ans[9000020];
	int pwi[30000];
	int phi(int x)
	{
		long long re=x;
		for(int i=2;i*i<x;i++)	
		{
			if(x%i==0)
			{
				re=re/i*(i-1);
				while(x%i==0)
					x/=i;
			}
		}
		if(x>1)
			re=re/x*(x-1);
		return re;
	}
	int gcd(int x,int y)
	{
		return y?gcd(y,x%y):x;
	}
	int lcm(int x,int y)
	{
		return x/gcd(x,y)*y;
	}
	void work()
	{
		q=((m-2)*(m-3)+2*m-3)%p;
		int phip=phi(p);
		int Q=lcm(phi(p),p);
		int LIM=min(n,Q);
		for(int i=0;i<p;i++)
			pwi[i]=pw(i,m);
		int pwq=1;
		for(int i=1;i<=LIM+1;i++)
		{
			ans[i]=(ans[i-1]+m*(m-1)%p*pwq%p*pwi[2*i%p])%p;
			pwq=pwq*q%p;
		}
		cout<<ans[n%Q];
		return;
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&p);
	if(m>200)
	{
		B::work();
		return 0;
	}
	N=m+1;
	q=((m-2)*(m-3)+2*m-3)%p;
	b.a[0][0]=1%p;
	for(int i=1;i<N;i++)
	{
		b.a[0][i]=1%p;
		for(int j=1;j<=i;j++)
		{
			b.a[j][i]=(b.a[j][i-1]+b.a[j-1][i-1])%p;
		}
	}
	for(int i=1;i<N;i++)
		for(int j=1;j<=i;j++)
			b.a[j][i]=b.a[j][i]*q%p;
	N++;
	b.a[N-1][N-1]=q%p;
	for(int i=0;i<N-1;i++)
		b.a[N-1][i]=1%p;
	for(int i=0;i<N;i++)
		a.a[0][i]=1%p;
	a.a[0][N-1]=q%p;
	mpw(n-1);
	long long ans=m*(m-1)%p;
	ans=ans*pw(2,m)%p;
	cout<<ans*a.a[0][N-2]%p;
	return 0;
}
