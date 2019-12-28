#include<iostream>
#include<algorithm>
using namespace std;
#define L (x<<1)
#define R (x<<1|1)
struct N{int l,r,c;}t[400020];
struct P{int x,y,h;}l[80020];
int z[80020],w[80020],n,cnt;
void B(int x,int l,int r)
{
	t[x].l=l;
	t[x].r=r;
	t[x].c=0;
	if(r>l+1)
	{
		B(L,l,(l+r)>>1);
		B(R,(l+r)>>1,r);
	}
}
void I(int x,int l,int r,int c)
{
	int ll=t[x].l,rr=t[x].r;
	if(l<=ll&&rr<=r)
	{
		if(c>=t[x].c)
			t[x].c=c;
		return;
	}
	int mid=(ll+rr)>>1;
	if(l<mid)I(L,l,r,c);
	if(r>mid)I(R,l,r,c);
}
int E(int t)
{
	int ll=1,rr=cnt;
	while(ll<rr)
	{
		int mid=(ll+rr)>>1;
		if(t>z[mid])
			ll=mid+1;
		else
			rr=mid;
	}
	return rr;
}
long long S(int x,int mx)
{
	mx=max(mx,t[x].c);
	int ll=t[x].l,rr=t[x].r;
	if(ll+1==rr)
		return (long long)mx*(z[rr]-z[ll]);
	return S(L,mx)+S(R,mx);
}
int main()
{
	int i;
	while(scanf("%d",&n)==1)
	{
		cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&l[i].x,&l[i].y,&l[i].h);
			w[cnt++]=l[i].x,w[cnt++]=l[i].y;
		}
		sort(w,w+cnt);
		n<<=1;
		z[1]=w[0];
		for(i=cnt=1;i<n;i++)
			if(w[i]!=w[i-1])
				z[++cnt]=w[i];
		B(1,1,cnt);
		n>>=1;
		for(i=0;i<n;i++)
			I(1,E(l[i].x),E(l[i].y),l[i].h);
		printf("%I64d\n",S(1,0));
			
	}
	return 0;
}
