#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef int ll;
ll a[1037][1037],b[1037][1037],c[1037][1037],x[1037],y[1037],z[1037],w[1037];
int n,i,j,k,t;
void scan(ll m[1037][1037])
{
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&m[i][j]);
}
void mul(ll x[1037][1037],ll y[1037],ll z[1037])
{
	memset(z,0,1037*4);
	for(i=0;z[i]=0,i<n;i++)
		for(j=0;j<n;j++)
			z[i]+=y[j]*x[i][j];
}
bool check(ll a[1037],ll b[1037])
{
	for(i=0;i<n;i++)
		if(a[i]!=b[i])
			return 0;
	return 1;
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		scan(a);
		scan(b);
		scan(c);
		for(i=0;i<n;i++)
			z[i]=rand()%1024;
		mul(b,z,w);
		mul(a,w,x);
		mul(c,z,y);
		puts(check(x,y)?"Yes":"No");
	}
	return 0;
}