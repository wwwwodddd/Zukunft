#include<stdio.h>
#include<string.h>
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define min(a,b) a>b?b:a
int n,m;
int a[200020];
int h[200020];
int f[200020];
int i,j,k,o,x,y;
struct TREE
{
	int l,r;
	int num;
}tree[600060];
void A(int x,int y,int idx)
{
	if(tree[idx].l==tree[idx].r)
	{
		tree[idx].num+=y;
		return;
	}
	int mid=(tree[idx].l+tree[idx].r)>>1;
	if(x<=mid)
		A(x,y,LL(idx));
	else if(x>mid)
		A(x,y,RR(idx));
	tree[idx].num=tree[LL(idx)].num+tree[RR(idx)].num;
}
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void U(int x,int y)
{
	int xx=F(x);
	int yy=F(y);
	if(xx==yy)
		return;
	f[yy]=xx;
	A(a[xx],-1,1);
	A(a[yy],-1,1);
	a[xx]+=a[yy];
	a[yy]=0;
	A(a[xx],1,1);
	return;
}
void B(int l,int r,int idx)
{
	tree[idx].l=l;
	tree[idx].r=r;
	if(tree[idx].l==tree[idx].r)
	{
		tree[idx].num=0;
		return ;
	}
	int mid=(tree[idx].l+tree[idx].r)>>1;
	B(l,mid,LL(idx));
	B(mid+1,r,RR(idx));
	tree[idx].num=tree[LL(idx)].num+tree[RR(idx)].num;
}
int Q(int idx)
{
	if(tree[idx].l==tree[idx].r)
		return tree[idx].l;
	if(tree[RR(idx)].num<x)
	{
		x-=tree[RR(idx)].num;
		return Q(LL(idx));
	}
	else
		return Q(RR(idx));
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		f[i]=i,a[i]=1;
	B(1,n,1);
	A(1,n,1);
	int num=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&o,&x);
		if(o==1)
			printf("%d\n",Q(1));
		else
		{
			scanf("%d",&y);
			U(x,y);
		}
	}
	return 0;
}