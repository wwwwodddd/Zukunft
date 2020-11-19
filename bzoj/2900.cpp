#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
long long tt[20];
long long n,ans;
int a[20],i,j;
int sm[20],sp[20];
void G(long long n)
{
	while(n)
	{
		a[++a[0]]=n%10;
		n/=10;
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
				ans+=(sp[9]*(a[i]-suc)-sp[a[i]-1]*10)*tt[i-2];
				ans-=a[i]*(n%tt[i-1]+1);
			}
	}
}
int main()
{
	tt[0]=1;
	for(i=1;i<19;i++)
		tt[i]=tt[i-1]*10;
	for(i=1;i<10;i++)
		sp[i]=sp[i-1]+i;
	for(i=1;i<10;i++)
		if(i&1)
			sm[i]=sm[i-1]+i;
		else
			sm[i]=sm[i-1]-i;
	while(scanf("%lld",&n),n)
	{
		memset(a,0,sizeof(a));
		G(n);
		if(n<10)
		{
			printf("%d\n",sm[n]);
			continue;
		}
		ans=sm[9];
		for(i=2;i<a[0];i++)
			if(i&1)
				ans+=9*tt[i-1]/2;
			else
				ans-=sp[9]*tt[i-2];
		if(i&1)
			work1();
		else
			work2();
		printf("%lld\n",ans);
	}
	return 0;
}
