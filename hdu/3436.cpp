#include<stdio.h>
#include<algorithm>
using namespace std;
int csc,i,t,x,y,n,q,N,ss;
int c[200020];
struct OP
{
	char s[10];
	int x;
}o[100020];
int a[100020];
int r[200020],p[100020];
void R(int x,int y)
{
	for(;x<=N;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int A(int x)
{
	int e=0,f=0,i;
	for(i=20;i>=0;i--)
	{
		if(e+(1<<i)<N&&f+c[e+(1<<i)]<x)
		{
			e+=(1<<i);
			f+=c[e];
		}
	}
	return e+1;
}
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		printf("Case %d:\n",++t);
		scanf("%d%d",&n,&q);
		a[0]=0;
		for(i=0;i<q;i++)
		{
			scanf("%s%d",o[i].s,&o[i].x);
			a[i+1]=o[i].x;
		}
		sort(a+1,a+1+q);
		n=unique(a+1,a+1+q)-(a+1);
		N=q+n;
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++)
		{
			R(q+i,a[i]-a[i-1]);
			r[q+i]=a[i];
			p[i]=q+i;
		}
		ss=q;
		for(i=0;i<q;i++)
		{
			if(strcmp(o[i].s,"Top")==0)
			{
				x=lower_bound(a+1,a+1+n,o[i].x)-a;
				R(p[x],-1);
				r[p[x]]--;
				p[x]=ss;
				R(ss,1);
				r[ss]=o[i].x;
				ss--;
			}
			if(strcmp(o[i].s,"Rank")==0)
			{
				y=A(o[i].x);
				x=G(y);
				printf("%d\n",r[y]-(x-o[i].x));
			}
			if(strcmp(o[i].s,"Query")==0)
			{
				x=lower_bound(a+1,a+1+n,o[i].x)-a;
				printf("%d\n",G(p[x]));
			}
		}
	}
	return 0;
}