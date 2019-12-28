#include<stdio.h>
#include<string.h>
__int64 a[15][3000];
int n,m,t;
void d1(int d,int mm)
{
	if(d==m)
		a[0][mm]++;
	if(d+1<=m)
		d1(d+1,(mm<<1));
	if(d+2<=m)
		d1(d+2,(mm<<2)|3);
	return;
}
void d2(int d,int nn,int mm)
{
	if(d==m)
		a[t][nn]+=a[t-1][mm];
	if(d+1<=m)
	{
		d2(d+1,mm<<1,nn<<1|1);
		d2(d+1,mm<<1|1,nn<<1);
	}
	if(d+2<=m)
		d2(d+2,mm<<2|3,nn<<2|3);
	return;
}
int f()
{		int i,j,k;
		memset(a,0,sizeof(a));
		if(n&m&1)
		{
			printf("0     ");
			return 0;
		}
		if(n>m)
		{
			m^=n;
			n^=m;
			m^=n;
		}
		d1(0,0);
		for(i=2;i<=n;i++)
		{
			t=i-1;
			d2(0,0,0);
		}
		printf("%I64d     ",a[n-1][(1<<m)-1]);
		return 0;
}
int main()
{
	int i,j,k;
/*	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			n=i;
			m=j;
			f();
		}
		printf("\n");
	}*/
	while(scanf("%d %d",&n,&m),n)
	{
		f();
	}
	return 0;
}