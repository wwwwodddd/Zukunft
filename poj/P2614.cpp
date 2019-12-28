#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,j,k;
int f[500020];
int l[120],d[120],c[120];
int main()
{
	scanf("%d %d",&n,&m);
	n*=1000;
	j=k=0x3f3f3f3f;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",l+i,d+i);
		d[i]-=l[i];
		j=min(j,l[i]);
	}
	for(int i=0;i<m;i++)
		k=min(k,l[i]*((j-1)/d[i]+1));
	if(n>=k)
		return puts("0"),0;
	f[0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<m;j++)
		{
			c[j]++;
			if(f[i])
				c[j]=0;
			if(c[j]<=d[j])
				f[i+l[j]]=1;
		}
	for(int i=n;;i--)
		if(f[i])
			return printf("%d\n",n-i),0;
	return 0;
}