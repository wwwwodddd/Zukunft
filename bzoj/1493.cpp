#include<stdio.h>
#include<iostream>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
using namespace std;
namespace XLk
{
	int n,c;
	int a[500020];
	int st,rv;
	struct N
	{
		int l,r,c,sa,lc,rc,cnt;	
	}t[2000020];
	void ud(int x)
	{
		t[x].lc=t[2*x].lc;
		t[x].rc=t[2*x+1].rc;
		t[x].cnt=t[2*x].cnt+t[2*x+1].cnt-(t[2*x].rc==t[2*x+1].lc);
	}
	int rep(int x)
	{
		if(rv==0)
		{
			x+=st;
			x=(x+n-1)%n+1;
		}
		else
		{
			x=st+2-x+n;
			x=(x+n-1)%n+1;
		}
		return x;
	}
	N mg(N a,N b)
	{
		N c;
		c.lc=a.lc;
		c.rc=b.rc;
		c.cnt=a.cnt+b.cnt-(a.rc==b.lc);
		return c;
	}
	void sam(int x,int c)
	{
		t[x].c=c;
		t[x].lc=t[x].rc=c;
		t[x].cnt=1;
		t[x].sa=1;
	}
	void pd(int x)
	{
		if(t[x].l==t[x].r)
			return;
		if(t[x].sa)
		{
			sam(2*x,t[x].c);
			sam(2*x+1,t[x].c);
		}
	}
	void bd(int l,int r,int x=1)
	{
		t[x].l=l;
		t[x].r=r;
		if(l==r)
		{
			sam(x,a[l]);
			return;
		}
		int m=l+r>>1;
		bd(l,m,x*2);
		bd(m+1,r,x*2+1);
		ud(x);
	}
	int ask(int p,int x=1)
	{
		if(t[x].l==t[x].r)
			return t[x].c;
		pd(x);
		int m=(t[x].l+t[x].r)>>1;
		if(p<=m)
			return ask(p,2*x);
		else
			return ask(p,2*x+1);
	}
	void cg(int l,int r,int z,int x=1)
	{
		if(r<t[x].l||l>t[x].r)
			return;
		pd(x);
		if(t[x].l>=l&&t[x].r<=r)
		{
			sam(x,z);
			return;
		}
		cg(l,r,z,x*2);
		cg(l,r,z,x*2+1);
		ud(x);
	}
	N qy(int l,int r,int x=1)
	{
		if(t[x].l>=l&&t[x].r<=r)
		{
			return t[x];
		}
		int m=(t[x].l+t[x].r)>>1;
		if(r<=m)
			return qy(l,r,x*2);
		if(l>m)
			return qy(l,r,x*2+1);
		return mg(qy(l,r,x*2),qy(l,r,x*2+1));
	}
	void work()
	{
		scanf("%d %d",&n,&c);
		fo(i,n)
			scanf("%d",a+i);
		bd(1,n);
		int q;
		scanf("%d",&q);
		char o[20];
		int x,y,z;
		fr(i,q)
		{
			printf("ope->%d::\n",i);
			fo(j,n)
				printf("%d ",ask(rep(j)));
			puts("end|\n");
			scanf("%s",o);
			if(*o=='F')
			{
				rv^=1;
			}
			else if(*o=='R')
			{
				scanf("%d",&x);
				x%=n;
				if(!rv)
					st=(st+n-x-1)%n+1;
				else
					st=(st+n+x-1)%n+1;
			}
			else if(*o=='S')
			{
				scanf("%d %d",&x,&y);
				x=rep(x);
				y=rep(y);
				int xc,yc;
				xc=ask(x);
				yc=ask(y);
				if(xc!=yc)
				{
					cg(x,x,yc);
					cg(y,y,xc);
				}
			}
			else if(*o=='P')
			{
				scanf("%d %d %d",&x,&y,&z);
				x=rep(x);
				y=rep(y);
				if(rv)
					swap(x,y);
				if(x>y)
				{
					cg(1,y,z);
					cg(x,n,z);	
				}
				else 
					cg(x,y,z);
			}
			else if(*o=='C')
			{
				if(o[1]=='S')
				{
					scanf("%d %d",&x,&y);
					x=rep(x);
					y=rep(y);
					if(rv)
						swap(x,y);
					if(x>y)
					{
						N ra=qy(1,y);
						N rb=qy(x,n);
						N rc=mg(rb,ra);
						printf("%d\n",rc.cnt);
					}
					else 
					{
						N rc=qy(x,y);
						printf("%d\n",rc.cnt);
					}
				}
				else
				{
					N ra=qy(1,n);
					int ans=ra.cnt;
					if(ra.lc==ra.rc)
						ans--;
					printf("%d\n",max(ans,1));
				}
			}
		}
	}
}
int main()
{
	XLk::work();
	while(getchar()+1);
}
