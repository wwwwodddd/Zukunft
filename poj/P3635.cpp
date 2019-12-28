#include<iostream>
#include<queue>
using namespace std;
const int inf=2147483647;
struct nod
{
int v,c,f;
bool operator <(const nod &a) const
	{
	return a.c<c;
	}
};
struct edg
{
int v,w,n;
}g[100200];
int d[1002][102],f[1002][102],a[1002],p[1002];
int n,m,e,l,s,t,b;
priority_queue<nod>q;
void add(int u,int v,int c)
{
	g[e].v=v;
	g[e].w=c;
	g[e].n=a[u];
	a[u]=e++;
}
int spfa()
{
	int i,u,v,w,c,r;
	nod z,x;
	z.v=s;
	z.c=z.f=0
	while(!q.empty())
		q.pop();
	q.push(z);
	while(!q.empty())
		{
		z=q.top();
		q.pop();
		u=z.v;
		c=z.c;
		f=z.f;
		t[u][f]=1;
		if(u==t)
			return z.c;
		if(f+1<=l&&!t[u][f+1]&&d[u][f+1]>d[u][f]+p[u])//加一单位的油 
		{
			d[u][f+1]=d[u][f]+p[u];
			x.v=u;
			x.f=f+1;
			x.c=d[u][f+1];
			q.push(x);
		}
		for(i=a[u];i!=-1;i=g[i].n)
		{
			v=g[i].v;
			w=g[i].w;
			if(f>=w&&!t[v][f-w]&&d[v][f-w]>c)//油足够时，开往下一站 
			{
				d[v][f-w]=c;
				x.v=v;
				x.f=f-w;
				x.c=d[v][f-w];
				q.push(x);
			}
		}
	}
	return -1;
}
int main()
{
	int i,j,k;
	memset(a,-1,sizeof(a));
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",p[i]);
	while(m--)
		{
		scanf("%d %d %d",&i,&j,&k);	
		add(i,j,k);
		add(j,i,k);
		}
	scanf("%d",&b);
	while(b--)
		{
		scanf("%d %d %d",&l,&s,&t);
		memset(f,0,sizeof(f));
		for(i=0;i<n;i++)
			for(j=0;j<=100;j++)
				d[i][j]=inf;
		d[s][0]=0;
		i=spfa();
		if(i!=-1)
			printf("%d\n",i);
		else
			printf("impossible");
		}
}