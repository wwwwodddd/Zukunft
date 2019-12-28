#include<stdio.h>
#include<string.h>
int f[520];
int m[520][520];
int n,i,j,t,r,l,g;
int F(int x)
{
	return f[x]==x?x:f[x]=F(f[x]);
}
void U(int x,int y)
{
	f[F(y)]=F(x);
}
int check(int x)
{
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(m[i][j]<=x)
				U(i,j);
	for(i=1;i<n;i++)
		if(F(i)!=F(i+1))
			return 0;
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&m[i][j]);
		l=1;
		r=65536;
		while(l<r)
		{
			g=((l+r)/2);
			if(check(g))
				r=g;
			else
				l=g+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
/*#include<stdio.h>
#include<string.h>
int m[520][520];
int d[520];
int b[520];
int n,i,j,t,ans;
int max(int x,int y)
{
	return x>y?x:y;
}
void prim(int st)
{
	int y,i,j;
	int min;
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++)
		d[i]=2147483647;
	y=0;
	d[st]=0;
	for(i=1;i<=n;i++)
	{
		min=2147483646;
		for(j=1;j<=n;j++)
			if((!b[j])&&(d[j]<min))
			{
				y=j;
				min=d[j];
			}
		ans=max(ans,min);
		b[y]=1;
		for(j=1;j<=n;j++)
			if((!b[j])&&(d[j]>m[y][j]))
				d[j]=m[y][j];
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&m[i][j]);
		prim(1);
		printf("%d\n",ans);
	}
	return 0;
}*/