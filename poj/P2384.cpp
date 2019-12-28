#include<stdio.h>
#include<string.h>
struct rec
{
	int px,py,bx,by,step;
}q[1000000];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n,i,j,k,stx,sty,ans,l,r;
char map[30][30];
int v[30][30][30][30];
int max(int x,int y)
{
	return x>y?x:y;
}
void init_renew()
{
	memset(v,-1,sizeof(v));
	scanf("%d",&n);
	memset(map,'#',sizeof(map));
	for(i=1;i<=n;i++)
		scanf("%s",map[i]+1);
	for(i=1;i<=n;i++)
		map[i][0]=map[i][n+1]=map[0][i]=map[i][n+1]='#';
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(map[i][j]=='*')
				stx=i,sty=j;
}
void bfs()
{
	int nx,ny;
	l=1;
	for(i=0;i<4;i++)
	{
		nx=stx+dx[i];
		ny=sty+dy[i];
		if(map[nx][ny]=='.')
		{
			r++;
			q[r].px=nx;
			q[r].py=ny;
			q[r].bx=stx;
			q[r].by=sty;
			v[nx][ny][stx][sty]=0;
		}
	}
	while(l<=r)
	{
		for(i=0;i<4;i++)
		{
			nx=q[l].px+dx[i];
			ny=q[l].py+dy[i];
			if (map[nx][ny]!='#'&&(nx!=q[l].bx||ny!=q[l].by)&&v[nx][ny][q[l].bx][q[l].by]==-1)
			{
				r++;
				q[r].px=nx;
				q[r].py=ny;
				q[r].bx=q[l].bx;
				q[r].by=q[l].by;
				q[r].step=q[l].step+1;
				v[nx][ny][q[l].bx][q[l].by]=q[r].step;
			}
		}
		for(i=0;i<4;i++)
		{
			nx=q[l].px+dx[i];
			ny=q[l].py+dy[i];
			if(nx==q[l].bx&&ny==q[l].by&&map[q[l].px-dx[i]][q[l].py-dy[i]]!='#'&&v[q[l].px-dx[i]][q[l].py-dy[i]][q[l].px][q[l].py]==-1)
			{
				r++;
				q[r].px=q[l].px-dx[i];
				q[r].py=q[l].py-dy[i];
				q[r].bx=q[l].px;
				q[r].by=q[l].py;
				q[r].step=q[l].step+1;
				v[q[l].px-dx[i]][q[l].py-dy[i]][q[l].px][q[l].py]=q[r].step;
			}
		}
		l++;
	}
}
void special()
{
	int i,j,k,l;
	ans=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				for(l=1;l<=n;l++)
				{
					if(k==stx&&l==sty)
						v[i][j][k][l]=0;
					ans=max(ans,v[i][j][k][l]);
				}
}
int main()
{
	init_renew();
	bfs();
	special();
	printf("%d\n",ans);
}