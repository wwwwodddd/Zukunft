#include<stdio.h>
#include<string.h>
int f[1005];
int g[205][205];
int a[205][205];
int m,t,s,e,n;
void F(int a[][205],int b[][205])
{
	int i,j,k;
	int r[205][205];
	memset(r,0x3f,sizeof(r));
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(r[i][j]>a[i][k]+b[k][j])
					r[i][j]=a[i][k]+b[k][j];
	memcpy(a,r,sizeof(r));
}
void result(int n)
{
	int i,j,k;
	while(n)
	{
		if(n&1)
			F(a,g);
		F(g,g);
		n>>=1;
	}
	return;
}
int main()
{
	int i,j;
	int x,y,l;
	scanf("%d%d%d%d",&m,&t,&s,&e);
	memset(g,0x3f,sizeof(g));
	memset(a,0x3f,sizeof(a));
	for(i=0;i<=200;i++)
		a[i][i]=0;
	for(i=1;i<=t;i++)
	{
		scanf("%d%d%d",&l,&x,&y);
		if(f[x]==0)
		{
			n++;
			f[x]=n;
		}
		if(f[y]==0)
		{
			n++;
			f[y]=n;
		}
		g[f[x]][f[y]]=l;
		g[f[y]][f[x]]=l;
	}
	result(m);
	printf("%d\n",a[f[s]][f[e]]);
	return 0;
}