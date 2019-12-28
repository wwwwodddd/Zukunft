#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
struct P{int x,y;P(int x=0,int y=0):x(x),y(y){}}p[105],q[10020];
int n,m,cnt;
char s[105][105];
int a[105][105];
int d[105][105];
int g[105][105];
int v[105],l[105];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
bool in(P &o)
{
	if(o.x<0||o.y<0||o.x>=n||o.y>=m)
		return 0;
	return a[o.x][o.y]&&d[o.x][o.y]==-1;
}
void bfs(P &o)
{
	memset(d,-1,sizeof(d));
	int b,f,k;
	b=f=0;
	q[f++]=o;
	d[o.x][o.y]=0;
	P u,w;
	while(b!=f)
	{
		u=q[b++];
		for(k=0;k<4;k++)
		{
			w=P(u.x+dx[k],u.y+dy[k]);
			if(in(w))
			{
				q[f++]=w;
				d[w.x][w.y]=d[u.x][u.y]+1;
			}
		}
	}
}
int prim(int n)
{
	int i,j,p,mn,re=0;
	memset(v,0,sizeof(v));
	v[0]=1;
	for(i=1;i<n;i++)
		l[i]=g[0][i];
	for(i=1;i<n;i++)
	{
		mn=inf;
		p=-1;
		for(j=0;j<n;j++)
			if(!v[j]&&mn>l[j])
				mn=l[p=j];
		re+=mn;
		v[p]=1;
		for(j=0;j<n;j++)
			if(!v[j]&&l[j]>g[p][j])
				l[j]=g[p][j];
	}
	return re;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		gets(s[0]);
		for(i=0;i<n;i++)
			gets(s[i]);
		cnt=1;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='#')
					a[i][j]=0;
				else
					a[i][j]=1;
				if(s[i][j]=='S')
					p[0]=P(i,j);
				if(s[i][j]=='A')
					p[cnt++]=P(i,j);
			}
		for(i=0;i<cnt;i++)
		{
			bfs(p[i]);
			for(j=0;j<cnt;j++)
				g[i][j]=d[p[j].x][p[j].y];
		}
		printf("%d\n",prim(cnt));
	}
	return 0;
}