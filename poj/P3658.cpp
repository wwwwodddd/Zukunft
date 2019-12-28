#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3ffffff
int p[100020],s[100020];
long long w[100020],h[100020];
int i,n,z;
long long sum,t[100020];
int main()
{
	scanf("%d",&n);
	w[0]=w[n+1]=1;
	h[0]=h[n+1]=inf;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d %I64d",&w[i],&h[i]);
		p[i]=i-1;
		s[i]=i+1;
		if(h[i]<h[z])
			z=i;
	}
	while(h[z]<inf)
	{
		t[z]=sum+w[z];
		s[p[z]]=s[z];
		p[s[z]]=p[z];
		if(h[p[z]]<h[s[z]])
		{
			w[p[z]]+=w[z];
			sum+=(h[p[z]]-h[z])*w[z];
			for(z=p[z];z>0&&h[p[z]]<h[z];z=p[z]);
		}
		else
		{
			w[s[z]]+=w[z];
			sum+=(h[s[z]]-h[z])*w[z];
			for(z=s[z];z>0&&h[s[z]]<h[z];z=s[z]);
		}
	}
	for(i=1;i<=n;i++)
		printf("%I64d\n",t[i]);
	return 0;
}