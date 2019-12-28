#include<iostream>
using namespace std;
struct Edge{int u,v,w;char c;}a[40010];
struct Node{int t,x,y;}q[40010];
inline int Abs(int x)
{
	return x>0?x:-x;
}
int F(int x)
{
	if(x!=q[x].t)
	{
		int t=F(q[x].t);
		q[x].x=q[x].x+q[q[x].t].x;
		q[x].y=q[x].y+q[q[x].t].y;
		q[x].t=t;
	}
	return q[x].t;
}
void U(int u,int v,int w,char c)
{
	int t1,t2;
	int x=F(u);
	int y=F(v);
	q[y].t=x;
	t1=q[v].x;
	t2=q[v].y;
	if(c=='E')
	{
		q[y].x=q[u].x+w;
		q[y].y=q[u].y;
	}
	else if(c=='W')
	{
		q[y].x=q[u].x-w;
		q[y].y=q[u].y;
	}
	else if(c=='N')
	{
		q[y].x=q[u].x;
		q[y].y=q[u].y+w;
	}
	else
	{
		q[y].x=q[u].x;
		q[y].y=q[u].y-w;
	}
	q[y].x-=t1;
	q[y].y-=t2;
}
int i,k,n,m,u,v,t,s;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d %d %s",&a[i].u,&a[i].v,&a[i].w,&a[i].c);
	scanf("%d",&k);
	for(i=1;i<=n;i++)
		q[i].t=i;
	while(k--)
	{
		scanf("%d %d %d",&u,&v,&t);
		while(s<t)
		{
			s++;
			U(a[s].u,a[s].v,a[s].w,a[s].c);
		}
		if(F(u)!=F(v))
			printf("-1\n");
		else
			printf("%d\n",Abs(q[u].x-q[v].x)+Abs(q[u].y-q[v].y));
	}
	return 0;
}