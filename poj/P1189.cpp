#include<stdio.h>
int n,m;
int i,j,k;
char g[60][60];
long long p[60][60],b,d;
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			scanf("%s",&g[i][j]);
	p[1][1]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			if(g[i][j]=='*')
			{
				p[i+1][j]+=p[i][j];
				p[i+1][j+1]+=p[i][j];
			}
			else
				p[i+2][j+1]+=p[i][j]*4;
	b=1;
	b<<=n;
	d=gcd(b,p[n+1][m+1]);
	printf("%I64d/%I64d",p[n+1][m+1]/d,b/d);
	return 0;
}