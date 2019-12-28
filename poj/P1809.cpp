#include<stdio.h>
int x,y,t,n,i,j,k;
long long ans,a[4];
long long C(long long x)
{
	return x*(x-1)*(x-2)/6;
}
long long C(long long x,long long y)
{
	return y*x*(x-1)/2;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		a[0]=a[1]=a[2]=a[3]=0;
		scanf("%d",&n);
		while(n--)
			scanf("%d %d",&x,&y),a[(x&1)*2+(y&1)]++;
		for(i=0;i<4;i++)
			ans+=C(a[i]);
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(j!=i)
					ans+=C(a[i],a[j]);
		printf("Scenario #%d:\n%I64d\n\n",++k,ans);
	}
	return 0;
}