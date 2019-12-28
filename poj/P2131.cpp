#include<stdio.h>
#include<string.h>
int lim=600010;
int c[600020];
int f[600020];
int v[600020];
int a[600020];
int z[600020],zz;
int q[600020];
int n,m,i,p;
void R(int x,int y)
{
	for(;x<lim;x+=x&-x)
		c[x]+=y;
	return;
}
int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
int A(int x)
{
	int i,e=0,d=0;
	for(i=20;i>=0;i--)
		if(e+(1<<i)<lim&&d+c[e+(1<<i)]<x)
		{
			e+=1<<i;
			d+=c[e];
		}
	return e+1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<lim;i++)
		f[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		F(a[i]);
		v[f[a[i]]]=1;
		R(f[a[i]],1);
		f[f[a[i]]]=f[a[i]]+1;
		a[i]=G(a[i]);
	}
	for(i=1;i<lim;i++)
		if(v[i])
			z[++zz]=i;
	memset(c,0,sizeof(c));
	for(i=1;i<=zz;i++)
		c[i]++;
	for(i=1;i<lim;i++)
		c[i+(i&-i)]+=c[i];
	for(i=n;i>0;i--)
	{
		p=A(a[i]);
		q[z[p]]=i;
		R(p,-1);
	}
	printf("%d\n",z[zz]);
	for(i=1;i<=z[zz];i++)
		printf("%d ",q[i]);
	return 0;
}