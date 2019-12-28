#include<iostream>
using namespace std;
#define id(x) (x+1)
int v[150000];
int g[150000];
int d[150000];
int s[150000];
int f[150000];
int a[2][150000];
int w[150000];
int T,h,O,c[150000];
int *l=a[0],*r=a[1];
int N(int k)
{
	T++;
	g[T]=w[T]=k;
	s[T]=1;
	f[T]=r[T]=l[T]=O;
	return T;
}
void RE(int x)
{
	if(x==O)
		return;
	swap(l[x],r[x]);
	v[x]^=1;
}
void A(int x,int k)
{
	if(x==O)
		return;
	d[x]+=k;
	w[x]+=k;
	g[x]+=k;
}
void pd(int x)
{
	if(x==O)
		return;
	if(v[x]) RE(l[x]),RE(r[x]),v[x]=0;
	if(d[x]) A(l[x],d[x]),A(r[x],d[x]),d[x]=0;
}
void ud(int x)
{
	if(x==O)
		return;
	s[x]=s[l[x]]+s[r[x]]+1;
	g[x]=min(w[x],min(g[l[x]],g[r[x]]));
}
void E(int x,int p)
{
	int k=f[x];
	pd(k),pd(x);
	a[!p][k]=a[p][x];
	if(a[p][x]!=O)
		f[a[p][x]]=k;
	f[x]=f[k];
	if(f[k]!=O)
		a[r[f[k]]==k][f[k]]=x;
	f[k]=x;
	a[p][x]=k;
	if(k==h)
		h=x;
	ud(k);
}
void P(int x,int F)
{
	int k,p1,p2;
	for(pd(x);f[x]!=F;)
	{
		k=f[x];
		p1=l[k]!=x;
		p2=l[f[k]]!=k;
		if(f[k]==F) E(x,1-p1);
		else if(p1==p2) {E(k,1-p1);E(x,1-p1);}
		else {E(x,1-p1);E(x,1-p2);}
	}
	ud(x);
}
void S(int k,int F)
{
	int q;
	for(q=h;;)
	{
		pd(q);
		int tmp=s[l[q]];
		if(tmp+1==k) break;
		if(k<=tmp) q=l[q];
		else q=r[q],k-=tmp+1;
	}	
	P(q,F);
}
void I(int x,int y)
{
	S(id(x),O);
	S(id(x+1),h);
	int nd=N(y);
	f[nd]=r[h];
	l[r[h]]=nd;
	ud(r[h]);
	ud(h);
	P(nd,O);
}
void del(int x)
{
	S(id(x-1),O);
	S(id(x+1),h);
	l[r[h]]=O;
	ud(r[h]);
	ud(h);
	P(r[h],O);
}
void RO(int x,int y,int z)
{
	S(id(y-z),O);
	S(id(x-1),h);	
	S(id(y+1),h);
	int nd=l[r[h]];
	l[r[h]]=O;
	if(r[l[h]]!=O)
	{
		S(id(x),l[h]);
		l[r[l[h]]]=nd;
		f[nd]=r[l[h]];
		ud(r[l[h]]);
	}
	else
	{
		r[l[h]]=nd;
		f[nd]=l[h];
	}
	ud(l[h]);
	ud(r[h]);
	ud(h);
	P(nd,O);
}
int M(int L,int R,int F)
{
	if(L>R)
		return O;
	int x=N(c[(L+R)/2]);
	l[x]=M(L,(L+R)/2-1,x);
	r[x]=M((L+R)/2+1,R,x);
	f[x]=F;
	ud(x);
	return x;
}
char o[20];
int main()
{
	int n,m,k,i,x,y,z,u;
	scanf("%d",&n);
	O=N(0);
	s[O]=0;
	g[O]=914990825;
	h=N(914990825);
	r[h]=N(914990825);
	f[r[h]]=h;
	ud(h);
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	l[r[h]]=M(1,n,r[h]);
	P(l[r[h]],O);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%s",o);
		if(o[0]=='A')
		{
			scanf("%d%d%d",&x,&y,&z);
			S(id(x-1),O);
			S(id(y+1),h);
			A(l[r[h]],z);
			P(l[r[h]],O);	
		}	
		else if(o[0]=='R'&&o[3]=='E')
		{
			scanf("%d%d",&x,&y);
			S(id(x-1),O);
			S(id(y+1),h);
			RE(l[r[h]]);
			P(l[r[h]],O);
		}
		else if(o[0]=='R'&&o[3]=='O')
		{
			scanf("%d%d%d",&x,&y,&z);
			u=y-x+1;
			z=(z%u+u)%u;
			if(z!=0)
			RO(x,y,z);
		}
		else if(o[0]=='I')
		{
			scanf("%d%d",&x,&y);
			I(x,y);
		}
		else if(o[0]=='D')
		{
			scanf("%d",&x);
			del(x);
		}		
		else if(o[0]=='M')
		{
			scanf("%d%d",&x,&y);
			S(id(x-1),O);
			S(id(y+1),h);
			printf("%d\n",g[l[r[h]]]);
		}
	}
	return 0;
}