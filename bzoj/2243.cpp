#include<stdio.h>
struct N
{
	int l,r,lv,rv,sm,sa;
	N(){}
	N(int l,int r,int lv,int rv,int sm,int sa):l(l),r(r),lv(lv),rv(rv),sm(sm),sa(sa){}
	N rev()
	{
		return N(r,l,rv,lv,sm,sa);
	}
}t[300000];
N operator+(const N &a,const N &b)
{
	if(a.sm==0)
		return b;
	if(b.sm==0)
		return a;
	if(a.rv==b.lv)
		return N(a.l,b.r,a.lv,b.rv,a.sm+b.sm-1,0);
	else
		return N(a.l,b.r,a.lv,b.rv,a.sm+b.sm,0);
}
int a[300000][2],h[300000],tot;
int w[300000];
int l[300000];
int u[300000];
int b[300000];
int f[300000];
int d[300000];
int p[300000];
int cnt;
void mt(int x,int l,int r)
{
	if(l==r)
	{
		t[x].l=l;
		t[x].r=r;
		t[x].lv=t[x].rv=w[b[l]];
		t[x].sm=1;
		t[x].sa=0;
		return;
	}
	int m=(l+r)>>1;
	mt(x*2,l,m);
	mt(x*2+1,m+1,r);
	t[x]=t[2*x]+t[2*x+1];
	return;
}
void add(int x,int y)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	h[x]=tot;
}
void pd(int x)
{
	if(t[x].l!=t[x].r&&t[x].sa)
	{
		t[2*x].lv=t[2*x+1].lv=t[x].lv;
		t[2*x].rv=t[2*x+1].rv=t[x].rv;
		t[2*x].sm=t[2*x+1].sm=1;
		t[2*x].sa=t[2*x+1].sa=1;
		t[x].sa=0;
	}
}
void dfs(int x)
{
	u[x]=1;
	int i,k=0,e,z;
	for(i=h[x];i;i=a[i][0])
		if((e=a[i][1])!=f[x])
		{
			f[e]=x;
			d[e]=d[x]+1;
			dfs(e);
			if(u[e]>k)
				k=u[z=e];
			u[x]+=u[e];
		}
	if(k)
		l[z]=1;
}
void bd(int x)
{
	if(l[x])
		l[x]=l[f[x]];
	else
		l[x]=x;
	int i,flag=0;
	for(i=h[x];i;i=a[i][0])
		if(a[i][1]!=f[x])
			flag=1,bd(a[i][1]);
	if(!flag)
	{
		int j;
		for(j=x;l[j]!=j;j=f[j])
			b[++cnt]=j;
		b[++cnt]=j;
	}
}
void R(int ll,int rr,int cc,int x=1)
{
	if(t[x].l>=ll&&t[x].r<=rr)
	{
		t[x].lv=t[x].rv=cc;
		t[x].sm=1;
		t[x].sa=1;
		return;
	}
	pd(x);
	int m=(t[x].l+t[x].r)>>1;
	if(ll>m)
		R(ll,rr,cc,x*2+1);
	else if(rr<=m)
		R(ll,rr,cc,x*2);
	else
		R(ll,rr,cc,x*2),R(ll,rr,cc,x*2+1);
	t[x]=t[2*x]+t[2*x+1];
}
N F(int ll,int rr,int x=1)
{
	pd(x);
	if(t[x].l>=ll&&t[x].r<=rr)
		return t[x];
	int m=(t[x].l+t[x].r)>>1;
	if(rr<=m)
		return F(ll,rr,x*2);
	if(ll>m)
		return F(ll,rr,x*2+1);
	return F(ll,rr,x*2)+F(ll,rr,x*2+1);
}
void cl(int a,int b,int c)
{
	while(l[a]!=l[b])
	{
		if(d[l[a]]<d[l[b]])
		{
			R(p[b],p[l[b]],c);
			b=f[l[b]];
		}
		else
		{
			R(p[a],p[l[a]],c);
			a=f[l[a]];
		}
	}
	if(p[a]>p[b])
		R(p[b],p[a],c);
	else
		R(p[a],p[b],c);
	return;
}
N G(int a,int b)
{
	N ra,rb,re;
	ra=rb=N(0,0,0,0,0,0);
	while(l[a]!=l[b])
	{
		if(d[l[a]]<d[l[b]])
		{
			rb=rb+F(p[b],p[l[b]]);
			b=f[l[b]];
		}
		else
		{
			ra=ra+F(p[a],p[l[a]]);
			a=f[l[a]];
		}
	}
	if(p[a]>p[b])
		re=rb+F(p[b],p[a])+ra.rev();
	else
		re=ra+F(p[a],p[b])+rb.rev();
	return re;
}
int n,m,i,x,y,z;
char o[9];
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",w+i);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1);
	bd(1);
	for(i=1;i<=cnt;i++)
		p[b[i]]=i;
	mt(1,1,cnt);
	while(m--)
	{
		scanf("%s",o);
		if(*o=='C')
		{
			scanf("%d %d %d",&x,&y,&z);
			cl(x,y,z);
		}
		else if(*o=='Q')
		{
			scanf("%d %d",&x,&y);
			printf("%d\n",G(x,y).sm);
		}
	}
	return 0;
}