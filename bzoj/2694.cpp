#include<stdio.h>
#include<iostream>
using namespace std;
int p[4000020],pp;
int v[4000020];
int l[4000020];
int f[4000020];
void P()
{
	f[1]=1;
	for(int i=2;i<=4000000;i++)
	{
		if(!v[i])
		{
			v[i]=i;
			p[pp++]=i;
			l[i]=i;
			f[i]=i-i*i;
		}
		for(int j=0;j<pp&&i*p[j]<=4000000;j++)
		{
			int u=i*p[j];
			v[u]=p[j];
			if(p[j]==v[i])
			{
				l[u]=l[i]*p[j];
				if(l[i]>p[j])
					f[u]=0;
				else
					f[u]=-p[j]*p[j]*p[j]*f[i/p[j]];
				break;
			}
			else
			{
				l[u]=p[j];
				f[u]=f[i]*f[p[j]];
			}
		}
	}
}
int work(int x,int y)
{
	int re=0,t1,t2,i,j;
	for(i=1;i<=x&&i<=y;i=j+1)
	{
		t1=x/i,t2=y/i;
		j=min(x/t1,y/t2);
		re+=(f[j]-f[i-1])*(t1*(t1+1)>>1)*(t2*(t2+1)>>1);
	}
	return re;
}
int main()
{
	P();
	for(int i=1;i<=4000000;i++)
		f[i]+=f[i-1];
	int q,n,m;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",work(n,m)&0x3fffffff);
	}
	return 0;
}
