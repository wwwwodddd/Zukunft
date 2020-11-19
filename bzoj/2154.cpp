#include<stdio.h>
#include<iostream>
using namespace std;
int mod=20101009;
bool v[10000020];
int p[1000020],pp;
long long s[10000020];
long long ans;
long long work(int n,int m)
{
	long long re=0,u,t1,t2;
	int i,j;
	for(i=1;i<=n&&i<=m;i=j+1)
	{
		t1=n/i,t2=m/i;
		j=min(n/t1,m/t2);
		u=((t1+1)*t1/2%mod)*((t2+1)*t2/2%mod)%mod;
		re=(re+u*(s[j]-s[i-1]))%mod;
	}
	return re;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n,m,i,j,t1,t2,u;
	scanf("%d %d",&n,&m);
	s[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!v[i])
			p[pp++]=i,s[i]=-1;
		for(j=0;j<pp&&p[j]*i<=n;j++)
		{
			v[p[j]*i]=1;
			s[p[j]*i]=-s[i];
			if(i%p[j]==0)
			{
				s[p[j]*i]=0;
				break;	
			}
		}
	}
	for(i=1;i<=n;i++)
		s[i]=(s[i-1]+(long long)i*i*s[i])%mod;
	for(i=1;i<=n&&i<=m;i=j+1)
	{
		t1=n/i,t2=m/i;
		j=min(n/t1,m/t2);
		u=(long long)(i+j)*(j-i+1)/2%mod;
		ans=(ans+work(t1,t2)*u)%mod;
	}
	printf("%I64d",(ans+mod)%mod);
	return 0;
}
