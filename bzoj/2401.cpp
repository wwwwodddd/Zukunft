// DNF
#include<iostream>
#include<stdio.h>
using namespace std;
int v[1000010],p[100010],pp;
int x,i,j,u,t;
long long f[1000010];
void P()
{
	for(i=2;i<=1000000;i++)
	{
		if(!v[i])
			p[pp++]=i,v[i]=i,f[i]=i*(i-1LL)+1;
		for(j=0;j<pp&&i*p[j]<=1000000;j++)
		{
			v[i*p[j]]=p[j];
			if(p[j]==v[i])
				break;
		}
	}
}
int main()
{
	P();
	f[1]=1;
	for(i=2;i<=1000000;i++)
	{
		u=i/v[i];
		if(v[i]==v[u])
			f[i]=(f[u]-f[u/v[i]])*v[i]*v[i]+f[u];
		else
			f[i]=f[u]*f[v[i]];
	}
	for(i=1;i<=1000000;i++)
		f[i]=(f[i]+1)/2*i+f[i-1];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		printf("%lld\n",f[x]);
	}
	return 0;
}
