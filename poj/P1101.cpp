#include<iostream>
using namespace std;
struct node{int x,y,w;node(){}node(int x,int y,int w):x(x),y(y),w(w){}}q[7000];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char g[80][80];
char v[80][80];
int sx,sy,ex,ey,w,h,b,f;
int i,j,k,t,ans;
int bfs()
{
	b=f=0;
	int tx,ty,i;
	q[f++]=node(sx,sy,0);
	while(b<f)
	{
		for(i=0;i<4;i++)
			for(tx=q[b].x+dx[i],ty=q[b].y+dy[i];;tx+=dx[i],ty+=dy[i])
			{
				if(tx==ex&&ty==ey)
					return q[b].w+1;
				if(g[tx][ty]=='X'||tx<0||tx>h+1||ty<0||ty>w+1)
					break;
				if(!v[tx][ty])
				{
					v[tx][ty]=1;
					q[f++]=node(tx,ty,q[b].w+1);
				}
			}
		b++;
	}
	return -1;
}
int main()
{
	while(scanf("%d%d",&w,&h),w+h)
	{
		getchar();
		memset(g,0,sizeof(g));
		printf("Board #%d:\n", ++t);
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
				scanf("%c", &g[i][j]);
			getchar();
		}
		k=0;
		while(scanf("%d%d%d%d",&sy,&sx,&ey,&ex),sx+sy+ex+ey)
		{
			memset(v,0,sizeof(v));
			ans=bfs();
			printf("Pair %d: ",++k);
			if(ans==-1)
				puts("impossible.");
			else
				printf("%d segments.\n",ans);
		}
		putchar('\n');
	}
	return 0;
}