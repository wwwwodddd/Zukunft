#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,d[100];
int v[6000];
int q[6000];
int p[6000];
int y[6000];
int b,f,r,i;
void P(int x)
{
	if(!x)
		return;
	P(p[x]);
	printf("%d",y[x]);
}
void bfs()
{
	memset(p,0,sizeof(p));
	memset(q,0,sizeof(q));
	memset(v,0,sizeof(v));
	memset(y,0,sizeof(y));
	b=f=0;
	q[f++]=0;
	while(b<f)
	{
		for(i=0;i<m;i++)
		{
			r=(q[b]*10+d[i])%n;
			if (!v[r]&&(d[i]>0||b!=0))
			{
				q[f]=r;
				p[f]=b;
				y[f]=d[i];
				v[r]=1;
				if(r==0)
				{
					P(f);
					printf("\n");
					return;
				}
				f++;
			}
		}
		b++;
	}
	printf("0\n");
	return;
}
int main()
{
	int i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<m;i++)
			scanf("%d",&d[i]);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		sort(d,d+m);
		bfs();
	}
	return 0;
}
