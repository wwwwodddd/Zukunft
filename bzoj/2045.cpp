#include<iostream>
#include<stdio.h>
using namespace std;
long long z,a,b,k,l,i,j;
int c[1000020];
int s[1000020];
int v[1000020];
int p[1000020];
void P()
{
	int i;
	for(i=0;i<=1000000;i++)
		c[i]=v[i]=p[i]=1;
	for(i=2;i<=1000000;i++)
		if(v[i])
			for(j=i;j<=1000000;j+=i)
				p[j]*=i,c[j]*=-1,v[j]=0;
}
int main()
{
	P();
	for(i=0;i<=1000000;i++)
		if(p[i]!=i)
			c[i]=0;
	for(i=1;i<=1000000;i++)
		c[i]+=c[i-1];
	cin>>a>>b>>k;
	a/=k,b/=k;
	z=0;
	for(j=1;j<=min(a,b);j++)
	{
		l=min(a/(a/j),b/(b/j));
		z+=(c[l]-c[j-1])*(b/j)*(a/j);
		j=l;
	}
	cout<<z;
	return 0;
}