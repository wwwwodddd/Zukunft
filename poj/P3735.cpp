#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long f[120][120];
long long a[120][120];
int n,m,k;
int x,y;
int i,j;
char c[5];
void mul(long long a[][120],long long b[][120])
{
	int i,j,k;
	long long r[120][120];
	memset(r,0,sizeof(r));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[i][j])
				for(k=1;k<=n;k++)
					r[i][k]+=a[i][j]*b[j][k];
	memcpy(a,r,sizeof(r));
	return;
}
void s(int x)
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
	while(scanf("%d %d %d",&n,&m,&k)&&n+m+k)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		n++;
		for(i=1;i<=n;i++)
			f[i][i]=a[i][i]=1;
		for(i=0;i<k;i++)
		{
			scanf("%s",c);
			if(c[0]=='s')
			{
				scanf("%d %d",&x,&y);
				for(j=1;j<=n;j++)
					swap(f[x][j],f[y][j]);
			}
			else if(c[0]=='g')
			{
				scanf("%d",&x);
				f[x][n]++;
			}
			else if(c[0]=='e')
			{
				scanf("%d",&x);
				for(j=1;j<=n;j++)
					f[x][j]=0;
			}
		}
		s(m);
		for(i=1;i<n;i++)
			printf("%I64d ",a[i][n]);
		printf("\n");
	}
	return 0;
}
