#include<stdio.h>
#include<algorithm>
long long m,z;
int n,a[100020];
int ok(int x)
{
	int s=z=0;
	for(int i=0;i<n;i++)
	{
		while(a[s]<a[i]-x)
			s++;
		z+=i-s;
	}
	return z>=m;
}
int main()
{
	for(;~scanf("%d",&n);)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		std::sort(a,a+n);
		m=((long long)n*(n-1)/2+1)/2;
		int l=0,r=2000000001;
		while(l<r)
			if(ok((l+r)/2))
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		printf("%d\n",l);
	}
	return 0;
}
