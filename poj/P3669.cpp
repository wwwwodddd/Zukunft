#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct N{int x,y,t;}q[200000];
int m,x,y,z,f,b,i,j,xx,yy,t;
int g[305][305];
int d[5][2]={{1,0},{0,1},{-1,0},{0,-1},{0,0}};
int v[305][305];
void push(int x,int y,int t)
{
	b++;
	q[b].x=x;
	q[b].y=y;
	q[b].t=t;
}
int main()
{
	memset(g,0x77,sizeof(g));
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		for(j=0;j<5;j++)
		{
			xx=x+d[j][0];
			yy=y+d[j][1];
			if(0<=xx&&0<=yy&&z<g[xx][yy])
				g[xx][yy]=z;
		}
	}
	push(0,0,0);
	while(f<b)
	{
		f++;
		if(g[q[f].x][q[f].y]==0x77777777)
		{
			printf("%d\n",q[f].t);
			return 0;
		}
		for(i=0;i<4;i++)
		{
			x=q[f].x+d[i][0];
			y=q[f].y+d[i][1];
			t=q[f].t;
			if(0<=x&&0<=y&&g[x][y]>t+1&&v[x][y]==0)
			{
				v[x][y]=1;
				push(x,y,t+1);
			}
		}
	}
	puts("-1");
	return 0;
}