#include<iostream>
#include<stdio.h>
using namespace std;
long long z;
int c[50020];
int s[50020];
int v[50020];
int p[50020];
int a,b,e,f,i,j,k,l,n;
void P()
{
	int i;
	for(i=0;i<=50000;i++)
		c[i]=v[i]=p[i]=1;
	for(i=2;i<=50000;i++)
		if(v[i])
			for(j=i;j<=50000;j+=i)
				p[j]*=i,c[j]*=-1,v[j]=0;
}
long long G(int a,int b)
{
	a/=k,b/=k;
	z=0;
	for(j=1;j<=min(a,b);j++)
	{
		l=min(a/(a/j),b/(b/j));
		z+=(long long)(c[l]-c[j-1])*(b/j)*(a/j);
		j=l;
	}
	return z;
}
int main()
{
	P();
	for(i=0;i<=50000;i++)
		if(p[i]!=i)
			c[i]=0;
	for(i=1;i<=50000;i++)
		c[i]+=c[i-1];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d %d",&a,&b,&e,&f,&k);
		printf("%lld\n",G(b,f)-G(b,e-1)-G(a-1,f)+G(a-1,e-1));
	}
	return 0;
}