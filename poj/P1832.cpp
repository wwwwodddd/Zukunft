#include<stdio.h>
#include<string.h>
int a[1020];
int f[1001][400];
int g[1001][400];
int b[400];
int o1[400];
int o2[400];
int cmp(int *x,int *y)
{
	if(x[0]>y[0])
		return 1;
	if(x[0]<y[0])
		return -1;
	for(int i=x[0];i>0;i--)
		if(x[i]>y[i])
			return 1;
		else if(x[i]<y[i])
			return -1;
	return 0;
}
int dec(int *x,int *y)
{
	for(int i=1;i<=y[0];i++)
		x[i]-=y[i];
	for(int i=1;i<=x[0];i++)
		if(x[i]<0)
		{
			x[i]+=10;
			x[i+1]--;
		}
	while(!x[x[0]]&&x[0])
		x[0]--;
	return 0;
}
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
	freopen("C:\\U\\u10.in","r",stdin);
	freopen("C:\\U\\u10.out","w",stdout);
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=n;i>0;i--)
			scanf("%d",&a[i]);
		memset(o1,0,sizeof(o1));
		memset(o2,0,sizeof(o2));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(b,0,sizeof(b));
		assign(f[0],0);
		assign(g[0],0);
		assign(b,1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				assign(f[i],f[i-1]);
				add(g[i-1],b,g[i]);
			}
			else if(a[i]==1)
			{
				assign(g[i],f[i-1]);
				add(g[i-1],b,f[i]);
			}
			pow();
		}
		assign(o1,f[n]);
		for(int i=n;i>0;i--)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(b,0,sizeof(b));
		assign(f[0],0);
		assign(g[0],0);
		assign(b,1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				assign(f[i],f[i-1]);
				add(g[i-1],b,g[i]);
			}
			else if(a[i]==1)
			{
				assign(g[i],f[i-1]);
				add(g[i-1],b,f[i]);
			}
			pow();
		}
		assign(o2,f[n]);
		if(cmp(o1,o2)>=0)
		{
			dec(o1,o2);
			print(o1);
		}
		else if(cmp(o1,o2)<0)
		{
			dec(o2,o1);
			print(o2);
		}
	}
	return 0;
}


