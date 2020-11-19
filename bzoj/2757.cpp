#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll lim=1000000000000000001ll,mo=20120427;
ll l[100020];
ll f[20][100020];
ll s[20][100020];
ll t[20],o[20];
int a[20],ac;
int lc;
int Q(ll x)
{
	int p=lower_bound(l,l+lc,x)-l;
	if(l[p]==x)
		return p;
	return -1;	
}
ll F(ll x,ll y)
{
	ac=0;
	ll re=0,pm=1,ps=0;
	for(ll i=x;i;i/=10)
		a[ac++]=i%10;
	if(y)
	{
		int r=Q(y);
		for(int i=0;i<ac;i++)
			re=(re+s[i][r])%mo;
		for(int i=ac-1;i>=0&&pm;i--)
		{
			for(int j=1;j<a[i];j++)
			{
				ll cm=pm*j;
				r=Q(y/cm);
				if(y%cm==0)
					re=(re+s[i][r]+(ps+j*t[i])*f[i][r])%mo;
			}
			pm*=a[i];
			ps+=a[i]*t[i];
		}
	}
	else
	{
		for(int i=0;i<ac;i++)
			re=(re+o[i])%mo;
		for(int i=ac-1;i>=0;i--)
		{
			for(int j=(i==ac-1?1:0);j<a[i];j++)
			{
				ll cm=pm*j;
				if(cm)
					re=(re+s[i][0]+(ps+j*t[i])*f[i][0])%mo;
				else
					re=(re+t[i]*(t[i]-1)/2+(ps+j*t[i])*t[i])%mo;
			}
			pm*=a[i];
			ps+=a[i]*t[i];
		}
	}
	if(pm==y)
		re=(re+x)%mo;
	return re;
}
int main()
{
	t[0]=1;
	for(int i=1;i<19;i++)
		t[i]=t[i-1]*10%mo;
	l[lc++]=0;
	for(ll i2=1;i2<lim;i2*=2)
		for(ll i3=i2;i3<lim;i3*=3)
			for(ll i5=i3;i5<lim;i5*=5)
				for(ll i7=i5;i7<lim;i7*=7)
					l[lc++]=i7;
	sort(l,l+lc);
	f[0][1]=1;
	for(int i=0;i<18;i++)
		for(int j=0;j<lc;j++)
			if(f[i][j]||s[i][j])
				for(int k=0;k<10;k++)
					if(l[j]*k<lim)
					{
						int r=Q(l[j]*k);
						f[i+1][r]=(f[i+1][r]+f[i][j])%mo;
						s[i+1][r]=(s[i+1][r]+s[i][j]+k*t[i]*f[i][j])%mo;
						if(!j&&k)
							o[i+1]=(o[i+1]+s[i][j]+k*t[i]*f[i][j])%mo;
					}
	int t;
	ll x,y,z;
	for(scanf("%d",&t);t--;)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		if(Q(z)<0)
			puts("0");
		else
			printf("%lld\n",(F(y,z)-F(x-1,z)+mo)%mo);
	}
}
