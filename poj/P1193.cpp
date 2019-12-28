#include<iostream>
using namespace std;
const int INF=0x3fffffff;
struct N{int m,t,p,s,n;}a[10000];
int q[10000],n,m,b,f,c,r,z;
bool alc(int p,int t)
{
	if (!r||a[r].s-0>=a[p].m)
	{
		a[p].n=r;
		r=p;
		a[p].t=t;
		a[p].s=0;
		return 1;
	}
	int i;
	for(i=r;a[i].n!=0;i=a[i].n)
		if(a[i].s+a[i].m-1+a[p].m<a[a[i].n].s)
		{
			a[p].n=a[i].n;
			a[i].n=p;
			a[p].s=a[i].s+a[i].m;
			a[p].t=t;
			return 1;
		}
	if(i&&n-(a[i].s+a[i].m)>=a[p].m)
	{
		a[i].n=p;
		a[p].n=0;
		a[p].s=a[i].s+a[i].m;
		a[p].t=t;
		return 1;
	}
	return 0;
}
void fap()
{
	int p=r,zz=INF;
	for(int i=r;i;)
	{
		if (a[i].t+a[i].p==z)
		{
			if (i==r) 
			{
				r=a[r].n;
				i=r;
			}
			else 
				i=a[p].n=a[i].n;
		}
		else
		{
			zz=min(zz,a[i].t+a[i].p);
			p=i;
			i=a[i].n;
		}
	}
	while(b<f)
		if(!alc(q[b],z))
			break; 
		else
		{
			zz=min(zz,a[q[b]].t+a[q[b]].p);
			++b;
		}
	z=zz;
}
void ins(int p)
{
	while(a[p].t>=z)
		fap();
	if(!alc(p,a[p].t))
		q[f++]=p;
	else
		z=min(z,a[p].t+a[p].p);
}
int sr()
{
	while(b<f)
		fap();
	int re=z;
	for(int i=r;i;i=a[i].n)
		re=max(re,a[i].t+a[i].p);
	return re;
}
int main()
{
	scanf("%d",&n);
	b=f=c=r=0;
	z=INF;
	for(int i=1;;i++)
	{
		scanf("%d%d%d",&a[i].t,&a[i].m,&a[i].p);
		if(a[i].t==0 && a[i].m==0 && a[i].p==0)
			break;
		ins(i);
	}
	printf("%d\n%d\n",sr(),f);
	return 0;
}