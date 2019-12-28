#include<stdio.h>
#include<string.h>
int tree[110][3];
int f[110][220][2];
int a[110];
int h[110];
int b[210][3];
char v[110];
int n,m,i,x,y;
int tot;
int max(int a,int b)
{
	return a>b?a:b;	
}
void add(int x,int y)
{
	tot++;
	b[tot][0]=h[x];
	h[x]=tot;
	b[tot][1]=y;
	return;
}
void build(int x)
{
	int i;
	v[x]=1;
	for(i=h[x];i;i=b[i][0])
	{
		if(v[b[i][1]])
			continue;
		tree[b[i][1]][1]=tree[x][0];
		tree[x][0]=b[i][1];
		build(b[i][1]);
	}
	return;
}
int dp(int i,int k,int temp)
{
	int j,l,r,re;
	if((k<0)||(i==0))
		return 0;
	if(k==0)
		return max(a[i],dp(tree[i][1],k,temp));
	if(f[i][k][temp]!=-1)
		return f[i][k][temp];
	l=tree[i][0];
	r=tree[i][1];
	if(temp==0)
	{
		re=max(dp(l,k-1,0),dp(r,k-2,0));
		for(j=0;j<k-2;j++)
		{
			re=max(re,dp(l,j,0)+dp(r,k-3-j,1));
			re=max(re,dp(l,j,1)+dp(r,k-4-j,0));
		}
	}
	else
	{
		re=max(dp(l,k-2,1),dp(r,k-2,1));
		for(j=0;j<k-3;j++)
			re=max(re,dp(l,j,1)+dp(r,k-4-j,1));
	}
	re+=a[i];
	return f[i][k][temp]=max(re,dp(r,k,temp));
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
	{
		tot=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(h,0,sizeof(h));
		memset(b,0,sizeof(b));
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			add(x,y);
			add(y,x);
		}
		memset(v,0,sizeof(v));
		memset(tree,0,sizeof(tree));
		build(1);
		memset(f,-1,sizeof(f));
		printf("%d\n",dp(1,m,0));
	}
	return 0;
}
