#include<stdio.h>
#include<string.h>
int b,f;
int d[520][520];
int v[520][520];
int g[520][520];
char s[1000];
int t,x,y,xx,yy,mm,nn;
int i,j,k;
int n,m;
int dx[4]={-1,-1,1,1};
int dn[4]={0,0,1,1};

int dy[4]={-1,1,-1,1};
int dm[4]={0,1,0,1};

int dd[4]={1,0,0,1};
int min(int x,int y)
{
	return x<y?x:y;
}
struct N
{
	int x,y;
}q[3000020];
int main()
{
	scanf("%d %d",&n,&m);
	getchar();
	memset(d,0x3f,sizeof d);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
			if(s[j]=='\\')
				g[i][j]=1;
			else
				g[i][j]=0;
	}
	if((n+m)%2)
	{
		printf("NO SOLUTION\n");
		return 0;
	}
	b=f=30000;
	q[f].x=0;
	q[f].y=0;
	f++;
	d[0][0]=0;
	while(b<f)
	{
		x=q[b].x;
		y=q[b].y;
		b++;
		v[x][y]=0;
		for(i=0;i<4;i++)
		{
			xx=x+dx[i];
			yy=y+dy[i];
			nn=x+dn[i];
			mm=y+dm[i];
			if(xx>=0&&xx<=n&&yy>=0&&yy<=m)
			{
				if(d[xx][yy]>d[x][y]+(g[nn][mm]^dd[i]))
				{
					d[xx][yy]=d[x][y]+(g[nn][mm]^dd[i]);
					if(!v[xx][yy])
					{
						if((g[nn][mm]^dd[i]))
						{
							q[f].x=xx;
							q[f].y=yy;
							f++;
						}
						else
						{
							b--;
							q[b].x=xx;
							q[b].y=yy;
						}
						v[xx][yy]=1;
					}
				}
			}	
		}
	}
	printf("%d\n",d[n][m]);
	return 0;
}