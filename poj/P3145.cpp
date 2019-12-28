#include<stdio.h>
#include<iostream>
using namespace std;
#define lim 500010
#define xlk 3020
int c[500020];
int ask[5020];
int a[500020],cnt;
int taam[500020],tim,csc;
void R(int x,int y)
{
	for(;x<lim;x+=x&-x)
		c[x]+=y;
}
int G(int x)
{
	if(x<0)
		return 0;
	int re=0;
	for(;x;x-=x&-x)
		re+=c[x];
	return re;
}
int A(int p)
{
	int i,num=G(p-1),d=0,e=0;
	for(i=20;i>=0;i--)
		if(d+(1<<i)<lim&&e+c[d+(1<<i)]<=num)
		{
			d+=(1<<i);
			e+=c[d];
		}
	return d+1;
}
char o[20];
int sf(int x)
{
	int mn=lim,k;
	for(int i=cnt-1;i>=0;i--)
	{
		int u=a[i]%x;
		if(u==0)
			return i+1;
		if(u<mn)
		{
			mn=u;
			k=i;
		}
	}
	return k+1;
}
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c1.out","w",stdout);
	int x,n,i,av,nv;
	while(scanf("%d",&n),n)
	{
		tim=0;
		printf("Case %d:\n",++csc);
		memset(c,0,sizeof(c));
		for(i=1;i<xlk;i++)
			ask[i]=i-1;
		while(n--)
		{
			scanf("%s %d",o,&x);
			if(o[0]=='B')
			{
				a[cnt++]=x;
				R(x,1);
				taam[x]=++tim;
			}
			else
			{
				if(tim==0)
				{
					printf("-1\n");
					continue;
				}
				if(x<xlk)
					printf("%d\n",sf(x));
				else
				{
					av=x-1;
					for(i=0;i<lim;i+=x)
					{
						nv=A(i);
						if(nv<lim&&(nv%x<av%x||nv%x==av%x&&taam[nv]>taam[av]))
							av=nv;
					}
					printf("%d\n",taam[av]);
				}
			}
		}
		puts("");
	}
	return 0;
}
