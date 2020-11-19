#include<iostream>
#include<stdio.h>
using namespace std;
int mod=98765431;
long long ans,t,s,z;
int n,a[50005];
int pw(int p)
{
	long long w,u,fac;
	if(p==1)
		return z=(n-1);
	else
	{
		w=pw(p>>1);
		u=(p+1)/2;
		fac=-1+(!((p&1)^(u&1)))*2;
		if(p&1)
			w=((w*(n-1))%mod*(z+fac)+(n-1))%mod;
		else
			w=w*(z+fac)%mod;
		z=z*z%mod;
		if(p&1)
			z=z*(n-1)%mod;
		return w;
	}
}
int main()
{
	int i,p;
	long long u;
	cin>>n>>t;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s=(a[i]+s)%mod;
	}
	p=1-(t&1)*2 ;
	u=pw(t-1)-p;
	for(i=1;i<=n;i++)
		cout<<(((u*s)%mod+a[i]*p)%mod+mod)%mod<<endl;
	return 0;
}