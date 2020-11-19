#include<iostream>
#include<stdio.h>
using namespace std;
int h[5020];
int f[5020];
int n,k,i,j,m;
double r;
int main()
{
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		f[i]=f[i-1];
		r=h[i]-h[i-1];
		for(j=i-1;j>=max(i-k,1);j--)
			if((double)(h[i]-h[j])/(i-j)<=r)
			{
				f[i]=min(f[i],f[j]);
				r=(double)(h[i]-h[j])/(i-j);
			}
			f[i]++;
	}
	printf("%d",f[n]);
	return 0;
}