#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int> ii;
struct N;
N *mlc();
struct N
{
	int l,r,lm,rm,sm,w;
	N *L,*R;
	N *set(int _l,int _r,N *_L,N *_R)
	{
		l=_l,r=_r,L=_L,R=_R;
		sm=L->sm+R->sm;
		lm=max(L->lm,L->sm+R->lm);
		rm=max(R->rm,R->sm+L->rm);
		return this;
	}
	N *bd(int _l,int _r,int d)
	{
		l=_l,r=_r;
		if(l+1==r)
		{
			lm=rm=max(0,w=sm=d);
			return this;
		}
		L=mlc()->bd(l,l+r>>1,d);
		R=mlc()->bd(l+r>>1,r,d);
		sm=L->sm+R->sm;
		lm=max(L->lm,L->sm+R->lm);
		rm=max(R->rm,R->sm+L->rm);
		return this;
	}
	N *cg(int x,int y)
	{
		if(l+1==r)
			return mlc()->bd(l,r,y);
		if(x<l+r>>1)
			return mlc()->set(l,r,L->cg(x,y),R);
		else
			return mlc()->set(l,r,L,R->cg(x,y));
	}
}t[400020],*tt=t;
N *rt[20020];
N *mlc()
{
	return tt++;
}
N qy(N *t,int l,int r)
{
	if(l<=t->l&&t->r<=r)
		return *t;
	int m=t->l+t->r>>1;
	if(r<=m)
		return qy(t->L,l,r);
	else if(l>=m)
		return qy(t->R,l,r);
	N L=qy(t->L,l,r);
	N R=qy(t->R,l,r);
	N re;
	re.sm=L.sm+R.sm;
	re.lm=max(L.lm,L.sm+R.lm);
	re.rm=max(R.rm,R.sm+L.rm);
	return re;
}
int work(N *t,int a,int b,int c,int d)
{
	N LE=qy(t,a,b-1 +1);
	N MI=qy(t,b,c +1);
	N RI=qy(t,c+1,d +1);
	return LE.rm+MI.sm+RI.lm;
}
int a[20020],n,m;
ii b[20020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		b[i].X=a[i],b[i].Y=i;
	}
	sort(b,b+n);
	rt[0]=mlc()->bd(0,n,1);
	for(int i=0;i<n;i++)
		rt[i+1]=rt[i]->cg(b[i].Y,-1);
	int w[6],ans=0,q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d",w+j);
			w[j]=(w[j]+ans)%n;
		}
		sort(w,w+4);
		int l=0,r=n;
		while(l+1<r)
		{
			int mid=l+r>>1;
			if(work(rt[mid],w[0],w[1],w[2],w[3])>=0)
				l=mid;
			else
				r=mid;
		}
		ans=b[l].X;
		printf("%d\n",ans);
	}
}
