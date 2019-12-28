#include<stdio.h>
#define MAX 50020
#define MAXINT 2147483647
struct EDGE
{
int st,ed,val;
}
edge[MAX];
int dis[MAX],n,min,max,m,x;
int bellman_ford()
{
int i,k;
for(i=min;i<=max;i++)
	dis[i]=-MAXINT;
dis[min]=0;
int over;
for(k=0;k<=max-min;k++)
	{
	over=1;
	for(i=0;i<n;i++)
	if(dis[edge[i].st]!=-MAXINT&&dis[edge[i].st]+edge[i].val>dis[edge[i].ed])
		{
		dis[edge[i].ed]=dis[edge[i].st]+edge[i].val;
		over=0;
		}
	for(i=min;i<max;i++)
		if(dis[i]!=-MAXINT&&dis[i]>dis[i+1])
			{
			dis[i+1]=dis[i];
			over=0;
			}
	for(i=max;i>min;i--)
		if(dis[i]!=-MAXINT&&dis[i]-1>dis[i-1])
			{
			dis[i-1]=dis[i]-1;
			over=0;
			}
	if(over)
		break;
	}
	return dis[max];
	}
int main()
{
int i;
while(scanf("%d",&n)!=EOF)
{
min=MAXINT;
max=0;
for(i=max;i<n;i++)
{
scanf("%d %d %d",&edge[i].st,&edge[i].ed,&edge[i].val);
if(edge[i].st>edge[i].ed)
{
x=edge[i].st;
edge[i].st=edge[i].ed;
edge[i].ed=x;
}
edge[i].ed++;
if(edge[i].ed>max)
max=edge[i].ed;
if(edge[i].st<min)
min=edge[i].st;
}
printf("%d\n",bellman_ford());
}
return 0;
}