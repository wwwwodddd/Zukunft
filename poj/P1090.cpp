#include<stdio.h>
#include<string.h>
int o;
int f[2][400];
int g[2][400];
int b[400];
int max(int x,int y)
{
	return x>y?x:y;
}
void assign(int *x,int y)
{
	int i;
	for(i=1;y;y/=10)
		x[i++]=y%10;
	x[0]=--i;
}
void add(int *a,int *b,int *c)
{
	int r[400];
	memset(r,0,sizeof(r));
	for(int i=max(a[0],b[0]);i>0;i--)
		r[i]=a[i]+b[i];
	for(int i=1;i<399;i++)
	{
		r[i+1]+=r[i]/10;
		r[i]%=10;
	}
	r[0]=399;
	while(!r[r[0]]&&r[0])
		r[0]--;
	memcpy(c,r,sizeof(r));
	return;
}
void pow()
{
	add(b,b,b);
	return;
}
void assign(int *x,int *y)
{
	for(int i=y[0];i>=0;i--)
		x[i]=y[i];
	return;
}
void print(int *x)
{
	for(int i=x[0];i>1;i--)
		printf("%d",x[i]);
	printf("%d\n",x[1]);
}
int main()
{
	int n;
	scanf("%d",&n);
	assign(f[0],0);
	assign(g[0],0);
	assign(b,1);
	for(int i=1;i<=n;i++)
	{
		memset(g[i&1],0,sizeof(g[0]));
		memset(f[i&1],0,sizeof(f[0]));
		scanf("%d",&o);
		if(o)
		{
			assign(g[i&1],f[1^i&1]);
			add(g[1^i&1],b,f[i&1]);
		}
		else
		{
			assign(f[i&1],f[1^i&1]);
			add(g[1^i&1],b,g[i&1]);
		}
		pow();
	}
	print(f[n&1]);
	return 0;
}