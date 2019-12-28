#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int f[120][120];
int a[120][120];
int b[120];
int n,m;
int ans;
int i,j;
void mul(int a[][120],int b[][120])
{
	int i,j,k;
	int r[120][120];
	memset(r,0,sizeof(r));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j])
				for(k=1;k<=n;k++)
					r[i][k]+=a[i][j]*b[j][k]%10000;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			r[i][j]%=10000;
	memcpy(a,r,sizeof(r));
	return;
}
void s()
{
	while(m)
	{
		if(m&1)
			mul(a,f);
		mul(f,f);
		m>>=1;
	}
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(i=n;i>0;i--)
			scanf("%d",&f[i][n]);
		scanf("%d",&m);
		for(i=1;i<=n;i++)
			f[i+1][i]=a[i][i]=1;
		s();
		ans=0;
		for(i=1;i<=n;i++)
			ans=(ans+b[i]*a[i][1])%10000;
		printf("%d\n",ans);
	}
	return 0;
}
