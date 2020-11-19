//DNF  MLE
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100020];
long long s[100020];
int ls[100020];
int lc;
struct N;
inline N *mlc();
struct N
{
	int s;
	int c;	
	N *L,*R;
	N *set(N *_L,N *_R)
	{
		L=_L;
		R=_R;
		s=L->s+R->s;
		c=L->c+R->c;
		return this;
	}
	N *bd(int l,int r,int d)
	{
		if(l+1==r)
		{
			this->c=d;
			this->s=d*ls[l];
			return this;
		}
/*		L=mlc()->bd(l,l+r>>1,0);
		R=mlc()->bd(l+r>>1,r,0);
		s=L->s+R->s;
		c=L->c+R->c;
*/		set(mlc()->bd(l,l+r>>1,0),mlc()->bd(l+r>>1,r,0));
		return this;
	}
	N *cg(int l,int r,int x)
	{
		if(l+1==r)
			return mlc()->bd(l,r,c+1);
		if(x<l+r>>1)
			return mlc()->set(L->cg(l,l+r>>1,x),R);
		else
			return mlc()->set(L,R->cg(l+r>>1,r,x));
	}
}t[1900000],*tt,*rt[100020],*rx,*ry;
inline N *mlc()
{
	return tt++;
}
int Q(int x)
{
	return lower_bound(ls,ls+lc,x)-ls;
}
int main()
{
	int cs,n,cc=0;
	for(scanf("%d",&cs);cs--;)
	{
		printf("Case #%d:",++cc);
		tt=t;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i),ls[i-1]=a[i],s[i]=s[i-1]+a[i];
		lc=n;
		sort(ls,ls+lc);
		lc=unique(ls,ls+lc)-ls;
		rt[0]=mlc()->bd(0,lc,0);
		for(int i=1;i<=n;i++)
			rt[i]=rt[i-1]->cg(0,lc,Q(a[i]));
		int x,y,l,r,ct,m;
		long long sm;
		for(scanf("%d",&m);m--;)
		{
			scanf("%d %d",&x,&y);
			x++,y++;
			ct=(y-x+1)/2;
			sm=0;
			rx=rt[x-1];
			ry=rt[y];
			l=0;
			r=lc;
			for(;l+1<r;)
			{
				if(ry->L->c-rx->L->c<=ct)
				{
					ct-=ry->L->c-rx->L->c;
					sm+=ry->L->s-rx->L->s;
					ry=ry->R;
					rx=rx->R;
					l=l+r>>1;
				}
				else
				{
					ry=ry->L;
					rx=rx->L;
					r=l+r>>1;
				}
			}
			printf("%I64d\n",((y-x+1)/2*ls[l]-sm)+(s[y]-s[x-1]-sm-(y-x+2)/2*ls[l]));
		}
	}
	return 0;
}
