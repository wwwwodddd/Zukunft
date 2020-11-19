#include<stdio.h>
int i,j,n,a,b,c,bb,ff;
long long x[1000020],s[1000020],g[1000020],y[1000020];
int q[1000020];
int shi(int x,int z)
{
	return y[x]-y[z]<2*a*s[i]*(s[x]-s[z]);
}
int xm(int i,int j,int k)
{
	return (y[i]-y[j])*(s[k]-s[j])>(y[j]-y[k])*(s[j]-s[i]);
}
int main()
{
	scanf("%d",&n);
	scanf("%d %d %d",&a,&b,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		s[i]=s[i-1]+x[i];
	}
	for(i=1;i<=n;i++)
	{
		while(bb<ff&&shi(q[bb],q[bb+1]))
			bb++;
		j=q[bb];
		g[i]=g[j]+a*(s[i]-s[j])*(s[i]-s[j])+b*(s[i]-s[j])+c;
		y[i]=g[i]+a*s[i]*s[i]-b*s[i];
		while(bb<ff&&xm(q[ff-1],q[ff],i))
			ff--;
		q[++ff]=i;
	}
	printf("%lld",g[n]);
	return 0;
}