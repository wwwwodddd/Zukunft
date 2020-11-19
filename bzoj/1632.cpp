//DNF
#include<stdio.h>
#include<string.h>
struct point{int x,y;}st,ed,t,u,z;
int dx[8]={-2,-1,1,2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int d[31][31],c[31][31],g[31][31],n,m,b,f,i,j;
char v[31][31];
long long p[31][31];
point q[1000020],r[31][31][901];
void find(point a)
{
	memset(v,0,sizeof(v));
	f=b=0;
	q[f++]=a;
	v[a.x][a.y]=1;
	while(b!=f)
	{
		z=q[b++];
		for(int i=0;i<8;i++)
		{
			u.x=z.x+dx[i];
			u.y=z.y+dy[i];
			if(u.x>=0&&u.x<n&&u.y>=0&&u.y<m)
			{
				if(g[u.x][u.y]==2||v[u.x][u.y])
					continue;
				else if(g[u.x][u.y]==1)
					q[f++]=u;
				else
					r[a.x][a.y][c[a.x][a.y]++]=u;
				v[u.x][u.y]=1;
			}
		}
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&g[i][j]);
			if(g[i][j]==3)
				st.x=i,st.y=j;
			else if(g[i][j]==4)
				ed.x=i,ed.y=j;
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(g[i][j]==0||g[i][j]==3||g[i][j]==4)
			{
				t.x=i;
				t.y=j;
				find(t);
			}
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[st.x][st.y]=0;
	p[st.x][st.y]=1;
	v[st.x][st.y]=1;
	b=f=0;
	q[f++]=st;
	while(b!=f)
	{
		z=q[(b++)%1000000];
		if(g[z.x][z.y]==4)
			continue;
		for(i=0;i<c[z.x][z.y];i++)
		{
			u=r[z.x][z.y][i];
			if(d[z.x][z.y]+1<d[u.x][u.y])
			{
				d[u.x][u.y]=d[z.x][z.y]+1;
				p[u.x][u.y]=p[z.x][z.y];
			}
			else if(d[z.x][z.y]+1==d[u.x][u.y])
				p[u.x][u.y]+=p[z.x][z.y];
			else
				continue;
			if(!v[u.x][u.y])
			{
				q[(f++)%1000000]=u;
				v[u.x][u.y]=1;
			}
		}
		p[z.x][z.y]=0;
		v[z.x][z.y]=0;
	}
	if(d[ed.x][ed.y]>0xffff)
		printf("-1\n");
	else
		printf("%d\n%lld\n",d[ed.x][ed.y]-1,p[ed.x][ed.y]);
	return 0;
}