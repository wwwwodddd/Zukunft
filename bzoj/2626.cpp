#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
struct P{int x,y,r;}a[100020];
struct N{int x,y,xn,yn,xm,ym,r;}t[400020];
bool cmpx(const P&a,const P&b){return a.x<b.x||a.x==b.x&&a.y<b.y;}
bool cmpy(const P&a,const P&b){return a.y<b.y||a.y==b.y&&a.x<b.x;}
void bd(int l,int r,int p,int z)
{
	sort(a+l,a+r,z?cmpx:cmpy);
	int m=l+r>>1;
	t[p].r=a[m],t[p].x=t[p].xm=t[p].xn=a[m].x,t[p].y=t[p].ym=t[p].yn=a[m].y;
	if(l+1==r)return;
	bd(l,m,p*2+1,!z);
	bd(m,r,p*2+2,!z);
	t[p].xm=max(t[p*2+1].xm,t[p*2+2].xm);
	t[p].xn=min(t[p*2+1].xn,t[p*2+2].xn);
	t[p].ym=max(t[p*2+1].ym,t[p*2+2].ym);
	t[p].yn=min(t[p*2+1].yn,t[p*2+2].yn);
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
}
