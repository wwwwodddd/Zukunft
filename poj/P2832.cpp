#include<stdio.h>
#include<stdlib.h>
int n,m,q,ans;
int f[10020];
int c[10020];
int p[10020];
int a[50020][3];
int b[10020][3];
int i,j,k,x,y;
int cmp0(const void *a,const void *b)
{
	return ((int*)a)[0]-((int*)b)[0];
}
int cmp2(const void *a,const void *b)
{
	return ((int*)a)[2]-((int*)b)[2];
}
int F(int x)
{
	return f[x]==x?x:f[x]=F(f[x]);
}
void U(int x,int y)
{
	if(x==y)
		return;
	ans+=c[x]*c[y];
	c[x]+=c[y];
	f[y]=f[x];
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(i=0;i<m;i++)
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	a[m][2]=2147483647;
	qsort(a,m,12,cmp2);
	for(i=0;i<q;i++)
	{
		b[i][1]=i;
		scanf("%d",&b[i][0]);
	}
	for(i=1;i<=n;i++)
		f[i]=i,c[i]=1;
	qsort(b,q,12,cmp0);
	i=0;
	for(j=0;j<q;j++)
	{
		for(;a[i][2]<=b[j][0];i++)
			U(F(a[i][0]),F(a[i][1]));
		p[b[j][1]]=ans;
	}
	for(j=0;j<q;j++)
		printf("%d\n",p[j]);
	return 0;
}