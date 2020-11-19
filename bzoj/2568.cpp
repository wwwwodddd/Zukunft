#include<stdio.h>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
multiset<int>s;
int c[300020];
int *r[20];
int n,ad,x,k;
char o[10];
void R(int *c,int x,int y,int z)
{
	for(x++;x<=z;x+=x&-x)
		c[x]+=y;
	return;
}
int G(int *c,int x)
{
	int re=0;
	for(x++;x;x-=x&-x)
		re+=c[x];
	return re;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=16;i++)
		r[i]=&c[1<<i];
	while(n--)
	{
		scanf("%s",o);
		if(*o=='I')
		{
			scanf("%d",&x);
			x-=ad;
			s.insert(x);
			for(i=1;i<=16;i++)
			{
				int f=x&(~0U>>32-i);
				if(f>=(1<<(i-1)))
				{
					R(r[i],(1<<i)-f+(1<<i-1),1,1<<i);
					R(r[i],(1<<i),-1,1<<i);
					R(r[i],0,1,1<<i);
					R(r[i],(1<<i)-f,-1,1<<i);
				}
				else
				{
					R(r[i],(1<<i-1)-f,1,1<<i);
					R(r[i],(1<<i)-f,-1,1<<i);
				}
			}
		}
		else if(*o=='A')
		{
			scanf("%d",&x);
			ad+=x;
		}
		else if(*o=='D')
		{
			scanf("%d",&x);
			x-=ad;
			int cc=s.count(x);
			s.erase(x);
			if(cc)
			{
				for(i=1;i<=16;i++)
				{
					int f=x&(~0U>>32-i);
					if(f>=(1<<(i-1)))
					{
						R(r[i],(1<<i)-f+(1<<i-1),-cc,1<<i);
						R(r[i],(1<<i),cc,1<<i);
						R(r[i],0,-cc,1<<i);
						R(r[i],(1<<i)-f,cc,1<<i);
					}
					else
					{
						R(r[i],(1<<i-1)-f,-cc,1<<i);
						R(r[i],(1<<i)-f,cc,1<<i);
					}
				}
			}
		}
		else if(*o=='Q')
		{
			scanf("%d",&k);
			k++;
			printf("%d\n",G(r[k],ad&((1<<k)-1)));
		}
	}
	return 0;
}