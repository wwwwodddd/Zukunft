#include<iostream>
#include<queue>
using namespace std;
int n,tx,ty,x,y;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
struct N{int x,y,z;}a,b;
bool v[1020][1020];
queue<N>q;
int bfs()
{
	while(!q.empty())
	{
		b=q.front();
		q.pop();
		if(b.x==tx&&b.y==ty)
			return b.z;
		for(int i=0;i<4;i++)
		{
			a.x=b.x+dx[i];
			a.y=b.y+dy[i];
			if(!v[a.x+500][a.y+500])
			{
				v[a.x+500][a.y+500]=1;
				a.z=b.z+1;
				q.push(a);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&tx,&ty,&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		v[x+500][y+500]=1;
	}
	a.x=a.y=a.z=0;
	v[500][500]=0;
	q.push(a);
	printf("%d\n",bfs());
}