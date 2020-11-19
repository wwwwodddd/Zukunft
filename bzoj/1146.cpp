#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
/*
var
a[][] tat h[] ;edges
e[][] tet g[] ;tarjan
f [] ;ufs
rp[] lp[] s[] cnt ;dfs order
t[] tt;seg
r[] ;seg root
v[] ;need doing pr not
w[] ;weight
c[] ;now root
ans ;returned value of Q
nq ;now query
qx[] qy[] qk[] ;queries
l[] lc ;sort & unique
*/
int a[200020][2],tat;
int h[100020];
int e[200020][2],tet;
int lca[200020];
int g[100020];
int s[100020],ss;
int rp[100020],cnt;
int lp[100020];
int w[100020];
int l[100020],lc;
int d[100020];
int p[100020];
int qx[100020];
int qy[100020];
int qk[100020];
int v[100020];
int f[100020];
int mk[100020];
int qc;
int n,m,cn,ans;
int ll,rr,dd;
void add(int x,int y)
{
	tat++;
	a[tat][0]=h[x];
	a[tat][1]=y;
	h[x]=tat;
}
void edd(int x,int y)
{
	tet++;
	e[tet][0]=g[x];
	e[tet][1]=y;
	g[x]=tet;
}
struct N;
inline N *mlc();
struct N
{
	int l,r,s;
	N *L,*R;
	inline N *set(int _l,int _r,N *_L,N *_R)
	{
		l=_l,r=_r,L=_L,R=_R;
		s=L->s+R->s;
		return this;
	}
	N *bd(int _l,int _r,int d)
	{
		l=_l,r=_r;
		if(l==r)
		{
			s=d;
			return this;
		}
		L=mlc()->bd(l,(l+r>>1),d);
		R=mlc()->bd((l+r>>1)+1,r,d);
		s=L->s+R->s;
		return this;
	}
	N *cg(int x,int y)
	{
		if(l==r)
			return mlc()->bd(l,r,s+y);
		if(x<=l+r>>1)
			return mlc()->set(l,r,L->cg(x,y),R);
		else
			return mlc()->set(l,r,L,R->cg(x,y));
	}
}t[2400000],*tt=t,*r[100020],*c[100020],*pr[100020],*pc[100020];
inline N *mlc()
{
	return tt++;
}
void R(int x,int p,int y)
{
	for(;x<=n;x+=x&-x)
		r[x]=r[x]->cg(p,y);
}
void clr(int x,int y)
{
	for(;x;x-=x&-x)
	{
		c[x]=r[x];
		pc[x]=pr[x];
		v[x]+=y;
	}
}
void Q(int x,int y)
{
	ans+=pc[x]->L->s*y;
	for(;x&&mk[x]!=qc;x-=x&-x)
		ans+=c[x]->L->s*v[x],mk[x]=qc;
}
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void tarjan(int x)
{
	int i;
	pr[ss+1]=pr[ss]=pr[ss]->cg(w[x],1);
	lp[x]=ss;
	s[ss++]=x;
	v[f[x]=x]=1;
	for(i=g[x];i;i=e[i][0])
		if(v[e[i][1]])
			lca[i-1>>1]=F(e[i][1]);
	for(i=h[x];i;i=a[i][0])
		if(!v[a[i][1]])
			d[a[i][1]]=d[x]+1,tarjan(a[i][1]),f[a[i][1]]=x;
	rp[x]=ss;
	pr[ss]=pr[ss]->cg(w[x],-1);
}
int RK(int x)
{
	return lower_bound(l,l+lc,x)-l;
}
void TR(int x,int y)
{
	if(y)
		for(;x&&mk[x]!=qc;x-=x&-x)
			pc[x]=pc[x]->R,c[x]=c[x]->R,mk[x]=qc;
	else
		for(;x&&mk[x]!=qc;x-=x&-x)
			pc[x]=pc[x]->L,c[x]=c[x]->L,mk[x]=qc;
}
int main()
{
	int x,y,z,i,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",w+i);
		l[lc++]=w[i];
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",qk+i,qx+i,qy+i);
		if(!qk[i])
			l[lc++]=qy[i],tet+=2;
		else
			edd(qx[i],qy[i]),edd(qy[i],qx[i]);
	}
	sort(l,l+lc);
	lc=unique(l,l+lc)-l;
	for(i=1;i<=n;i++)
		w[i]=RK(w[i]);
	ss=1;
	r[1]=mlc()->bd(0,lc-1,0);
	pr[1]=mlc()->bd(0,lc-1,0);
	for(i=1;i<=n;i++)
		r[i]=r[1];
/*	for(i=1;i<=n;i++)
	{
		R(lp[i],w[i],1);
		R(rp[i],w[i],-1);
	}*/
	tarjan(1);
	memset(v,0,sizeof(v));
	for(i=0;i<m;i++)
	{
		if(!qk[i])
		{
			x=qx[i];
			R(lp[x],w[x],-1);
			R(rp[x],w[x],1);
			w[x]=RK(qy[i]);
			R(lp[x],w[x],1);
			R(rp[x],w[x],-1);
		}
		else
		{
			x=qx[i];
			y=qy[i];
			z=lca[i];
			k=qk[i];
			if(d[x]+d[y]-2*d[z]+1<k)
			{
				puts("invalid request!");
				continue;
			}
			k=d[x]+d[y]-2*d[z]+2-k;
			clr(lp[x],1);
			clr(lp[y],1);
			clr(lp[z],-2);
			ll=0;
			rr=lc-1;
			while(ll<rr)
			{
				ans=0;
				qc++;
				Q(lp[x],1);
				Q(lp[y],1);
				Q(lp[z],-2);
				if(ans+(w[lca[i]]<=(ll+rr)/2&&w[lca[i]]>=ll)>=k)
				{
					qc++;
					TR(lp[x],0);
					TR(lp[y],0);
					TR(lp[z],0);
					rr=(ll+rr)/2;
				}
				else
				{
					k-=ans+(w[lca[i]]<=(ll+rr)/2&&w[lca[i]]>=ll);
					qc++;
					TR(lp[x],1);
					TR(lp[y],1);
					TR(lp[z],1);
					ll=(ll+rr)/2+1;
				}
			}
			clr(lp[x],-1);
			clr(lp[y],-1);
			clr(lp[z],2);
			printf("%d\n",l[ll]);
		}
	}
	return 0;
}