#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
char g[40][40][40];
char c[20];
int v[40][40][40];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
struct S{int x,y,z,t;}A,B;
queue<S>q;
void push(S s)
{
	if(v[s.z][s.y][s.x])
		return;
	v[s.z][s.y][s.x]=1;
	q.push(s);
	return;
}
int bfs(int sx,int sy,int sz)
{	
	A.x=sx;
	A.y=sy;
	A.z=sz;
	A.t=0;
	q.push(A);
	while(!q.empty())
	{
		A=q.front();
		q.pop();
		if(g[A.z][A.y][A.x]=='E')
			return A.t;
		for(int i=0;i<6;i++)
		{
			B.x=A.x+dx[i];
			B.y=A.y+dy[i];
			B.z=A.z+dz[i];
			B.t=A.t+1;
			if(g[B.z][B.y][B.x]=='O'||g[B.z][B.y][B.x]=='E')
				push(B);
		}
	}
	return -1;
}
int main()
{
	int m,n,l,i,j,k,sx,sy,sz,r;
	while(scanf("%s %d",c,&n)!=EOF)
	{
		while(!q.empty())
			q.pop();
		memset(v,0,sizeof(v));
		memset(g,0,sizeof(g));
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%s",g[i][j]+1);
		scanf("%d %d %d",&sx,&sy,&sz);
		sx++,sy++,sz++;
		g[sx][sy][sz]='E';
		scanf("%d %d %d",&sx,&sy,&sz);
		sx++,sy++,sz++;
		r=bfs(sx,sy,sz);
		scanf("%s",c);
		if(r==-1)
			printf("NO ROUTE\n");
		else
			printf("%d %d\n",n,r);
	}
	return 0;
}
