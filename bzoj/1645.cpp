#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct N{int l,r,w;}t[400020];
struct P{int x,y,h;}a[80020];
int h[80020],n,cnt;
int l,r,w;
void bd(int x,int l,int r)
{
	t[x].l=l;
	t[x].r=r;
	if(l==r)
		return;
	bd(x*2,l,(l+r)/2);
	bd(x*2+1,(l+r)/2+1,r);
}
void ud(int x)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].w=max(t[x].w,w);
		return;
	}
	if(t[x].r<l||t[x].l>r)
		return;
	ud(x*2);
	ud(x*2+1);
}
int E(int t)
{
	return lower_bound(h,h+cnt,t)-h;
}
long long qy(int x,int mx)
{
	mx=max(mx,t[x].w);
	if(t[x].l==t[x].r)
		return (long long)mx*(h[t[x].l+1]-h[t[x].l]);
	return qy(x*2,mx)+qy(x*2+1,mx);
}
int main()
{
	int i;
	scanf("%d",&n);
	cnt=0;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].h);
		h[i*2]=a[i].x;
		h[i*2+1]=a[i].y;
	}
	cnt=2*n;
	sort(h,h+cnt);
	cnt=unique(h,h+cnt)-h;
	h[cnt]=h[cnt-1];
	bd(1,0,cnt-1);
	n;
	for(i=0;i<n;i++)
	{
		l=E(a[i].x);
		r=E(a[i].y)-1;
		w=a[i].h;
		ud(1);
	}
	printf("%lld\n",qy(1,0));
	return 0;
}