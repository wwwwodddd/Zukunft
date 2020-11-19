#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
struct P
{
	ll x,y;
	P(ll x=0,ll y=0):x(x),y(y){}
}p[4],pt,lm,rm;
bool operator<(const P &a,const P &b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
set<P>us,ls;
set<P>::iterator it,il,iu,ill,iuu;
long long ans,dd;
int n;
ll xm(P a,P b,P c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
void uins(P u)
{
	iu=us.upper_bound(u);
	il=iu;
	il--;
	if(xm(*il,*iu,u)<=0)
		return;
	ans+=xm(*il,*iu,u);
	while(il!=us.begin())
	{
		ill=il;
		ill--;
		if(xm(*ill,*il,u)>=0)
		{
			ans+=xm(*ill,*il,u);
			us.erase(il);
			il=ill;
		}
		else
			break;
	}
	while(iu!=--us.end())
	{
		iuu=iu;
		iuu++;
		if(xm(*iuu,u,*iu)>=0)
		{
			ans+=xm(*iuu,u,*iu);
			us.erase(iu);
			iu=iuu;
		}
		else
			break;
	}
	us.insert(u);
}
void lins(P u)
{
	iu=ls.upper_bound(u);
	il=iu;
	il--;
	if(xm(*il,u,*iu)<=0)
		return;
	ans+=xm(*il,u,*iu);
	while(il!=ls.begin())
	{
		ill=il;
		ill--;
		if(xm(*ill,u,*il)>=0)
		{
			ans+=xm(*ill,u,*il);
			ls.erase(il);
			il=ill;
		}
		else
			break;
	}
	while(iu!=--ls.end())
	{
		iuu=iu;
		iuu++;
		if(xm(*iuu,*iu,u)>=0)
		{
			ans+=xm(*iuu,*iu,u);
			ls.erase(iu);
			iu=iuu;
		}
		else
			break;
	}
	ls.insert(u);
}
int main()
{
	int i;
	for(i=0;i<3;i++)
		scanf("%I64d %I64d",&p[i].x,&p[i].y);
	sort(p,p+3);
	lm=p[0];
	rm=p[2];
	us.insert(p[0]);
	us.insert(p[2]);
	ls.insert(p[0]);
	ls.insert(p[2]);
	uins(p[1]);
	lins(p[1]);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%I64d %I64d",&pt.x,&pt.y);
		if(pt<lm)
		{
			while(us.size()>1&&(dd=xm(pt,*us.begin(),*++us.begin()))>=0)
			{
				ans+=dd;
				us.erase(us.begin());
			}
			us.insert(pt);
			while(ls.size()>1&&(dd=xm(pt,*++ls.begin(),*ls.begin()))>=0)
			{
				ans+=dd;
				ls.erase(ls.begin());
			}
			ls.insert(pt);
			lm=pt;
		}
		else if(rm<pt)
		{
			while(us.size()>1&&(dd=xm(pt,*++us.rbegin(),*us.rbegin()))>=0)
			{
				ans+=dd;
				us.erase(--us.end());
			}
			us.insert(pt);
			while(ls.size()>1&&(dd=xm(pt,*ls.rbegin(),*++ls.rbegin()))>=0)
			{
				ans+=dd;
				ls.erase(--ls.end());
			}
			ls.insert(pt);
			rm=pt;
		}
		else
		{
			uins(pt);
			lins(pt);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}