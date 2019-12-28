#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int v=131,l,ac,t;
long long p[100];
long long h[100];
long long r[100];
long long a[100020];
char s[100];
int main()
{
	for(int i=p[0]=1;i<100;i++)
		p[i]=p[i-1]*v;
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s+1);
		memset(h,0,sizeof h);
		memset(r,0,sizeof r);
		l=strlen(s+1);
		for(int i=1;i<=l;i++)
			h[i]=h[i-1]*v+s[i];
		for(int i=l;i>0;i--)
			r[i]=r[i+1]*v+s[i];
		ac=0;
		for(int i=1;i<l;i++)
		{
			long long x=h[i],y=h[l]-h[i]*p[l-i];
			long long X=r[1]-r[i+1]*p[i],Y=r[i+1];
			a[ac++]=x+y*p[i];
			a[ac++]=x+Y*p[i];
			a[ac++]=X+y*p[i];
			a[ac++]=X+Y*p[i];
			a[ac++]=y+x*p[l-i];
			a[ac++]=y+X*p[l-i];
			a[ac++]=Y+x*p[l-i];
			a[ac++]=Y+X*p[l-i];
		}
		sort(a,a+ac);
		printf("%d\n",unique(a,a+ac)-a);
	}
}