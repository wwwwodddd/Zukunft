#include<stdio.h>
#define mid 100000
int n,m,p,i;
int a[100020];
int f[100020];
int c[200020];
int d[200020];
long long ans;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==m)
			p=i;
	}
	c[mid]++;
	d[mid]++;
	for(i=p-1;i>0;i--)
	{
		if(a[i]>m)
			f[i]=f[i+1]+1;
		else
			f[i]=f[i+1]-1;
		c[f[i]+mid]++;
	}
	for(i=p+1;i<=n;i++)
	{
		if(a[i]>m)
			f[i]=f[i-1]-1;
		else
			f[i]=f[i-1]+1;
		d[f[i]+mid]++;
	}
	for(i=1;i<200000;i++)
		ans+=c[i]*d[i];
	printf("%d",ans);
	return 0;
}