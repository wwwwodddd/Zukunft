#include<stdio.h>
#include<iostream>
using namespace std;
long long g[10020],c[10020],t[10020],s;
int q[10020],b,f,i,n;
int K(int i,int j,int k)
{
	return ((g[k]-s*c[k])-(g[i]-s*c[i]))*(c[k]-c[j])<((g[k]-s*c[k])-(g[j]-s*c[j]))*(c[k]-c[i]);
}
long long work(int i,int j)
{
	return g[j]+(c[i]-c[j])*t[i]+s*(c[n]-c[j]);
}
int main()
{
	q[1]=0;
	scanf("%d%lld",&n,&s);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i],&c[i]);
		t[i]+=t[i-1];
		c[i]+=c[i-1];
	}
	for(i=1;i<=n;i++)
	{
		while((b<f)&&(work(i,q[b])>work(i,q[b+1])))
			b++;
		g[i]=work(i,q[b]);
		while((b<f)&&(K(q[f],q[f-1],i)))
			f--;
		q[++f]=i;
	}
	printf("%lld\n",g[n]);
	return 0;
}