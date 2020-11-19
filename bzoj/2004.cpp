#include<stdio.h>
#include<string.h>
int n,k,p,tot,mo=30031;
int a[130][130],b[130][130],d[130000][20];
void dfs(int x,int y)
{
	if(x==k)
	{
		memcpy(d[tot+1],d[tot],sizeof d[0]);
		tot++;
		return;
	}
	for(int i=y;i<p;i++)
	{
		d[tot][i]=1;
		dfs(x+1,i+1);
		d[tot][i]=0;
	}
}
void mul(int a[130][130],int b[130][130])
{
	int c[130][130];
	memset(c,0,sizeof c);
	for(int i=0;i<tot;i++)
		for(int k=0;k<tot;k++)
			if(a[i][k])
				for(int j=0;j<tot;j++)
					c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mo;
	for(int i=0;i<tot;i++)
		for(int j=0;j<tot;j++)
			a[i][j]=c[i][j];
}
int main()
{
	scanf("%d %d %d",&n,&k,&p);
	dfs(1,1);
	for(int i=0;i<tot;i++)
		for(int j=0;j<tot;j++)
		{
			int t=d[j][1];
			for(int k=1;k<p;k++)
				if(d[i][k]&&!d[j][k+1])
					t--;
			if(!t)
				b[i][j]=1;
		}
	n-=k;
	for(a[0][0]=1;n;n>>=1)
	{
		if(n&1)
			mul(a,b);
		mul(b,b);
	}
	printf("%d\n",a[0][0]);
	return 0;
}
