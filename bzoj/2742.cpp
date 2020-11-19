#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<ii>z;
int n;
int a[300];
int b[300],bc;
int c[300],cc;
int p[300];
int q[300];
bool cmp(ii a,ii b)
{
	return (ll)a.x*b.y<b.x*a.y;
}
void fac(int x,int *a,int &c)
{
	for(int i=1;i*i<=x;i++)
		if(x%i==0)
		{
			a[c++]=i;
			if(i*i<x)
				a[c++]=x/i;
		}
}
int cal(int _p,int _q,int mo)
{
	*p=*q=1;
	for(int i=1;i<=n;i++)
		p[i]=(long long)p[i-1]*_p%mo,q[i]=(long long)q[i-1]*_q%mo;
	int re=0;
	for(int i=0;i<=n;i++)
		re=(re+(long long)a[i]%mo*p[i]%mo*q[n-i]%mo)%mo;
	return re==0;
}
int ok(int _p,int _q)
{
	for(int i=7777;i<7890;i++)
		if(!cal(_p,_q,i))	
			return 0;
	return 1;
}
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d",a+i);
	int e=0;
	for(;!a[e];e++)
		;
	fac(abs(a[e]),b,bc);
	fac(abs(a[n]),c,cc);
	for(int i=0;i<bc;i++)
		for(int j=0;j<cc;j++)
			if(gcd(b[i],c[j])==1)
			{
				if(ok(b[i],c[j]))
				{
					z.push_back(ii(b[i],c[j]));
		//			printf("%d %d\n",b[i],c[j]);
				}
				if(ok(-b[i],c[j]))
				{
					z.push_back(ii(-b[i],c[j]));
		//			printf("%d %d\n",-b[i],c[j]);
				}
			}
	if(!a[0])
		z.push_back(ii(0,1));
	sort(z.begin(),z.end(),cmp);
	printf("%d\n",z.size());
	for(vector<ii>::iterator i=z.begin();i!=z.end();i++)
		if(i->second==1)
			printf("%d\n",i->first);
		else
			printf("%d/%d\n",i->first,i->second);
	while(1);
	return 0;
}
