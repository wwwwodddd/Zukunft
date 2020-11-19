#include<stdio.h>
#include<string.h>
struct N{int l,r,sum,sa;}t[400020];
int csc,tst,l,r,n,m;
void bd(int p,int l,int r)
{
	t[p].l=l;
	t[p].r=r;
	if(l==r)
	{
		t[p].sum=1;
		return;
	}
	bd(p*2,l,(l+r)/2);
	bd(p*2+1,(l+r)/2+1,r);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	return;
}
void same(int p,int x)
{
	t[p].sum=(t[p].r-t[p].l+1)*x;
	t[p].sa=x;
	return;
}
void pd(int p)
{
	if(t[p].l!=t[p].r)
		if(t[p].sa)
			same(p*2,t[p].sa),same(p*2+1,t[p].sa),t[p].sa=0;
	return;
}
void ud(int p,int x)
{
	pd(p);
	if(t[p].l>=l&&t[p].r<=r)
	{
		same(p,x);
		return;
	}
	if(t[p].l>r||t[p].r<l)
		return;
	ud(p*2,x);
	ud(p*2+1,x);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	return;
}
int main()
{
	int x;
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d %d",&n,&m);
		memset(t,0,sizeof(t));
		bd(1,1,n);
		while(m--)
		{
			scanf("%d %d %d",&l,&r,&x);
			ud(1,x);
		}
		printf("Case %d: The total value of the hook is %d.\n",++tst,t[1].sum);
	}
	return 0;
}