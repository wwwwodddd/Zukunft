#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int f[6][6];
int a[6][6];
int b[6];
int n,m;
int ans;
int i,j;
void mul(int a[][6],int b[][6])
{
	int i,j,k;
	int r[6][6];
	memset(r,0,sizeof(r));
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			if(a[i][j])
				for(k=1;k<=4;k++)
					r[i][k]+=a[i][j]*b[j][k]%m;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			r[i][j]%=m;
	memcpy(a,r,sizeof(r));
	return;
}
void s()
{
	while(n)
	{
		if(n&1)
			mul(a,f);
		mul(f,f);
		n>>=1;
	}
}
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		b[1]=b[2]=1%m;
		b[3]=5%m;
		b[4]=11%m;
		f[1][4]=-1;
		f[2][4]=1;
		f[3][4]=5;
		f[4][4]=1;
		for(i=1;i<=4;i++)
			f[i+1][i]=a[i][i]=1;
		s();
		ans=0;
		for(i=1;i<=4;i++)
			ans=(ans+b[i]*a[i][1])%m;
		printf("%d\n",(ans%m+m)%m);
	}
	return 0;
}
