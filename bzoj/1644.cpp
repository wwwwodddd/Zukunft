#include<stdio.h>
#include<string.h>
int n,m;
int i,j,k;
int b,f,x,y,ex,ey;
int qx[1000020];
int qy[1000020];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char c[120][120];
int d[120][120];
int main()
{
	scanf("%d",&n);
	memset(c,'x',sizeof(c));
	for(i=1;i<=n;i++)
	{
		scanf("%s",c[i]+1);
		c[i][n+1]='x';
	}
	memset(d,0x3f,sizeof(d));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(c[i][j]=='A')
			{
				d[i][j]=-1;
				qx[f]=i;
				qy[f]=j;
				f++;
			}
			if(c[i][j]=='B')
				ex=i,ey=j;
		}
	while(b<f)
	{
		for(k=0;k<4;k++)
		{
			x=qx[b];
			y=qy[b];
			while(c[x][y]!='x')
			{
				if(d[x][y]>d[qx[b]][qy[b]]+1)
				{
					d[x][y]=d[qx[b]][qy[b]]+1;
					qx[f]=x;
					qy[f]=y;
					f++;
				}
				x+=dx[k];
				y+=dy[k];
			}
		}
		b++;
	}
	printf("%d",d[ex][ey]);
	return 0;
}