#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int mo=1000000001;
int q[400],p[30],c,n,l;
int e[2][1050],*f,*g;
long long ans=1;
int work(int x)
{
	memset(e,0,sizeof e);
	f=e[0],g=e[1],f[0]=1;
	for(int i=0;1<<i<=x;i++)
	{
		swap(f,g);
		memset(f,0,sizeof e[0]);
		for(l=0;p[l]<=x>>i;l++)
			;
		for(int j=0;j<c;j++)
			if(g[j])
				for(int k=0;k<c&&q[k]<1<<l;k++)
					if((q[j]&q[k])==0)
						f[k]=(f[k]+g[j])%mo;
	}
	return f[0]+f[1]+f[2];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<1<<12;i++)
		if((i&i<<1)==0)
			q[c++]=i;
	for(int i=p[0]=1;i<12;i++)
		p[i]=p[i-1]*3;
	for(int i=1;i<=n;i++)
		if(i%2&&i%3)
			ans=ans*work(n/i)%mo;
	printf("%lld",ans);
	return 0;
}
