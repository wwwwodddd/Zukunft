#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<set>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
long long tt[100];
long long n,ans;
int a[100],i,j,d;
int sm[100],sp[100];
void G(long long n)
{
	while(n)
	{
		a[++a[0]]=n%d;
		n/=d;
	}
}
void work1()
{
	int i;
	if(n&1)
		ans+=(n-tt[a[0]-1]+1)/2;
	else
	{
		ans+=(n-tt[a[0]-1])/2;
		for(i=a[0];i>0;i--)
			if(i&1)
				ans-=a[i];
			else
				ans+=a[i];
	}
}
void work2()
{
	int i,j,len,suc;
	len=a[0];
	for(i=len;i>0;i--)
	{
		if(i==len)
			suc=1;
		else
			suc=0;
		if(a[i]!=0)
			if(i&1)
			{
				ans+=sp[a[i]-1]*tt[i-1];
				ans+=a[i]*(n%tt[i-1]+1);
			}
			else
			{
				ans+=(sp[d-1]*(a[i]-suc)-sp[a[i]-1]*d)*tt[i-2];
				ans-=a[i]*(n%tt[i-1]+1);
			}
	}
}
inline int S(int x,int y)
{
	if(y&1)
		return x;
	else
		return x+sm[d-1];
}
void work3()
{
	int sgn=1;
	for(i=1;i<a[a[0]];i++)
		ans+=sgn*S(i,a[0]),sgn=-sgn;
	ans+=(n+1)%tt[a[0]-1]%2*a[a[0]]*sgn;
	for(i=a[0]-1;i>0;i--)
	{
		sgn=-sgn;
		for(j=0;j<a[i]||i==1&&j==a[i];j++)
			ans+=sgn*S(j,i),sgn=-sgn;
		if(i!=1)
			ans+=(n%tt[i-1]+1)%2*a[i]*sgn;
	}
}
void work4()
{
	int i,j,len,suc;
	len=a[0];
	for(i=len;i>0;i--)
	{
		if(i==len)
			suc=1;
		else
			suc=0;
		if(a[i]!=0)
			if(i&1)
			{
				ans-=(ll)sp[a[i]-1]*tt[i-1];
				ans-=(ll)a[i]*(n%tt[i-1]+1);
			}
			else
			{
				ans-=(ll)(sp[d-1]*(a[i]-suc)-(ll)sp[a[i]-1]*d)*tt[i-2];
				ans+=(ll)a[i]*(n%tt[i-1]+1);
			}
	}
}
int main()
{
	scanf("%d %lld",&d,&n);
	G(n);
	for(i=1;i<d;i++)
		if(i&1)
			sm[i]=sm[i-1]+i;
		else
			sm[i]=sm[i-1]-i;
	if(n<d)
	{
		printf("%d",sm[n]);
		return 0;
	}
	tt[0]=1;
	for(i=1;tt[i-1]<=n/d;i++)
		tt[i]=tt[i-1]*d;
	for(i=1;i<d;i++)
		sp[i]=sp[i-1]+i;
	ans=sm[d-1];
	if(d%2==0)
	{
		for(i=2;i<a[0];i++)
			if(i&1)
				ans+=(d-1)*tt[i-1]/2;
			else
				ans-=sp[d-1]*tt[i-2];
		if(i&1)
			work1();
		else
			work2();
	}
	else
	{
		for(i=2;i<a[0];i++)
			if(i&1)
				ans-=d/2;
			else
				ans+=sp[d-1]*tt[i-2];
		if(i&1)
			work3();
		else
			work4();
	}
	printf("%lld",ans);
	return 0;
}
