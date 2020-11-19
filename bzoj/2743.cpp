#include<stdio.h>
int c[1000020];
int l[1000020];
int p[1000020];
int h[1000020];
int a[1000020][2];
int z[1000020];
int x,n,m;
void R(int x,int y)
{
	for(;x<=n;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int main()
{
	scanf("%d %*d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		p[i]=l[x];
		l[x]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&a[i][1],&x);	
		a[i][0]=h[x];
		h[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[p[i]])
			R(p[p[i]],-1);
		if(p[i])
			R(p[i],1);
		if(h[i])
		{
			int u=G(i);
			for(int j=h[i];j;j=a[j][0])
				z[j]=u-G(a[j][1]-1);
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",z[i]);
	return 0;
}
