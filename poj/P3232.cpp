#include<stdio.h>
int t,n,m,k,a[100020];
int i,j,l,r;
int check(int x)
{
	long long q=0,c;
	c=x;
	c*=m;
	for(i=0;i<n;i++)
		if(a[i]>x)
			if((a[i]-x-1)/(k-1)+1>x)
				return 0;
			else
				q+=(a[i]-x-1)/(k-1)+1;
	return q>c?0:1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l=r=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>r)
				r=a[i];
		}
		scanf("%d %d",&m,&k);
		if(k==1)
			l=r;
		while(l!=r)
			if(check((l+r)/2))
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		printf("%d\n",r);
	}
	return 0;
}