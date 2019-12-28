#include<stdio.h>
#include<string.h>
#define LL(x) x<<1
#define RR(x) (x<<1)|1
int n,m,x,y;
struct N{int l,r,v;}t[500020];
int min(int x,int y)
{
	return x<y?x:y;
}
void B(int idx,int l,int r)
{
	t[idx].l=l;
	t[idx].r=r;
	t[idx].v=0x3f3f3f3f;
	if(l==r)
		return;
	B(LL(idx),l,(l+r)/2);
	B(RR(idx),(l+r)/2+1,r);
	return;
}
void R(int idx,int x,int y)
{
	if(t[idx].l==t[idx].r)
	{
		t[idx].v=min(t[idx].v,y);
		return;
	}
	int m=(t[idx].l+t[idx].r)/2;
	if(x<=m)
		R(LL(idx),x,y);
	else
		R(RR(idx),x,y);
	t[idx].v=min(t[LL(idx)].v,t[RR(idx)].v);
	return;
}
int Q(int idx,int l,int r)
{
	if(l<=t[idx].l&&r>=t[idx].r)
		return t[idx].v;
	int m=(t[idx].l+t[idx].r)/2;
	if(l>m)
		return Q(RR(idx),l,r);
	if(r<=m)
		return Q(LL(idx),l,r);
	return min(Q(LL(idx),l,r),Q(RR(idx),l,r));
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
	{
		B(1,1,n);
		R(1,1,0);
		while(m--)
		{
			scanf("%d %d",&x,&y);
			R(1,y,Q(1,x,y-1)+1);
		}
		printf("%d\n",Q(1,n,n));
	}
	return 0;
}