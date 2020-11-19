#include<stdio.h>
struct N{int l,r,s;}t[200020];
int l,r,csc,i,n,tst;
int a[50020];
void bd(int p,int l,int r)
{
	t[p].l=l;
	t[p].r=r;
	if(l==r)
	{
		t[p].s=a[l];
		return;
	}
	bd(p*2,l,(l+r)/2);
	bd(p*2+1,(l+r)/2+1,r);
	t[p].s=t[p*2].s+t[p*2+1].s;
	return;
}
int qy(int p=1)
{
	if(t[p].l>=l&&t[p].r<=r)
		return t[p].s;
	if(t[p].l>r||t[p].r<l)
		return 0;
	return qy(p*2)+qy(p*2+1);
}
void ud(int p,int x,int y)
{
	if(t[p].l==t[p].r)
	{
		t[p].s+=y;
		return;
	}
	if(x<=t[p*2].r)
		ud(p*2,x,y);
	else
		ud(p*2+1,x,y);
	t[p].s=t[p*2].s+t[p*2+1].s;
}
char o[20];
int main()
{
	int x,y;
	scanf("%d",&csc);
	while(csc--)
	{
		printf("Case %d:\n",++tst);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bd(1,1,n);
		while(1)
		{
			scanf("%s",o);
			if(o[0]=='E')
				break;
			else if(o[0]=='Q')
			{
				scanf("%d %d",&l,&r);
				printf("%d\n",qy());
			}
			else if(o[0]=='A')
			{
				scanf("%d %d",&x,&y);
				ud(1,x,y);
			}
			else if(o[0]=='S')
			{
				scanf("%d %d",&x,&y);
				ud(1,x,-y);
			}
		}
	}
	return 0;
}