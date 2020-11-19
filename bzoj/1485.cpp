#include<stdio.h>
long long ans,mod;
int p[2000020],pp;
int v[2000020];
int a[2000020];
int n,i,j,k;
void P()
{
	for(i=2;i<=2*n;i++)
	{
		if(!v[i])
			p[pp++]=i;
		for(j=0;j<pp&&p[j]*i<=2*n;j++)
		{
			v[p[j]*i]=1;
			if(i%p[j]==0)
				break;
		}
	}
}
void div(int x,int z)
{
	for(i=0;i<pp;i++)
		for(j=x;j;)
			a[i]+=z*(j/=p[i]);
}
long long pw(long long x,int y)
{
	long long re=1;
	while(y)
	{
		if(y&1)
			re=re*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return re;
}
int main()
{
	scanf("%d %d",&n,&mod);
	P();
	div(2*n,1);
	div(n,-1);
	div(n+1,-1);
	ans=1;
	for(i=0;i<pp;i++)
		ans=ans*pw(p[i],a[i])%mod;
	printf("%lld",ans);
	return 0;
}