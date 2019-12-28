#include<stdio.h>
#include<stdlib.h>
double l,r;
int a[1020],b[1020];
double d[1020],sum;
int i,j,n,m;
int cmp(const void *a,const void *b)
{
	if(*(double*)a>*(double*)b)
		return -1;
	else
		return 1;
}
int check(double k)
{
	sum=0;
	for(i=0;i<n;i++)
		d[i]=a[i]-b[i]*k;
	qsort(d,n,8,cmp);
	for(i=0;i<n-m;i++)
		sum+=d[i];
	if(sum>0)
		return 1;
	else
		return 0;
}
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		for(i=0;i<n;i++)
			scanf("%d",b+i);
		l=0;
		r=1;
		while(r-l>0.0001)
			if(check((r+l)/2))
				l=(r+l)/2;
			else
				r=(r+l)/2;
		printf("%0.lf\n",100*(l+r)/2);
	}
	return 0;
}