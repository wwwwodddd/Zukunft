#include<stdio.h>
int i,j,n,k,b,f,t,q[500020];
long long a[500020],s[500020],g[500020];
long long G(int k,int j)
{
	return g[j]-g[k]-s[j]+s[k]+j*a[j+1]-k*a[k+1];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		b=0;
		f=1;
		for(i=1;i<=n;i++)
		{
			while(b<f-1&&G(q[b+1],q[b])>=i*(a[q[b]+1]-a[q[b+1]+1]))
				b++;
			j=q[b];
			g[i]=g[j]+s[i]-s[j]-(i-j)*a[j+1];
			while(b<f-1&&G(q[f-1],q[f-2])*(a[q[f-1]+1]-a[i-k+2])>=G(i-k+1,q[f-1])*(a[q[f-2]+1]-a[q[f-1]+1]))
				f--;
			if(i>=2*k-1)
				q[f++]=i-k+1;
		}
		printf("%I64d\n",g[n]);
	}
	return 0;
}