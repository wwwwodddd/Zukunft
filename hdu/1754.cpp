#include<stdio.h>
#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
struct N{int l,r,mx;}t[800020];
int n,m,l,r;
int a[200020];
void bd(int p,int l,int r)
{
	t[p].l=l;
	t[p].r=r;
	if(l==r)
	{
		t[p].mx=a[l];
		return;
	}
	bd(p*2,l,(l+r)/2);
	bd(p*2+1,(l+r)/2+1,r);
	t[p].mx=max(t[p*2].mx,t[p*2+1].mx);
	return;
}
int qy(int p=1)
{
	if(t[p].l>=l&&t[p].r<=r)
		return t[p].mx;
	if(t[p].l>r||t[p].r<l)
		return -inf;
	return max(qy(p*2),qy(p*2+1));
}
void ud(int p,int x,int y)
{
	if(t[p].l==t[p].r)
	{
		t[p].mx=y;
		return;
	}
	if(x<=t[p*2].r)
		ud(p*2,x,y);
	else
		ud(p*2+1,x,y);
	t[p].mx=max(t[p*2].mx,t[p*2+1].mx);
}
char o[5];
int main()
{
	int i,x,y;
	while(scanf("%d %d",&n,&m)+1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bd(1,1,n);
		while(m--)
		{
			scanf("%s",o);
			if(o[0]=='Q')
			{
				scanf("%d %d",&l,&r);
				printf("%d\n",qy());
			}
			else
			{
				scanf("%d %d",&x,&y);
				ud(1,x,y);
			}
		}
	}
	return 0;
}