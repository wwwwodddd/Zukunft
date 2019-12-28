#include<stdio.h>
#include<string.h>
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int d[10][10][10][10];
int a[100],b[100];
int n,m,ix,iy,l,x,y,dis;
int ans;
char c[200];
void bfs(int x,int y)
{
	int q[10000];
	int b,f,nx,ny,i;
	b=0;
	f=1;
	q[0]=(x<<8)|y;
	d[x][y][x][y]=0;
	while(b<=f)
	{
		nx=(q[b]&0x0000ff00)>>8;
		ny=(q[b]&0x000000ff);
		for(i=0;i<8;i++)
			if(nx+dx[i]>0&&nx+dx[i]<9&&ny+dy[i]>0&&ny+dy[i]<9)
				if(d[x][y][nx+dx[i]][ny+dy[i]]>d[x][y][nx][ny]+1)
				{
				d[x][y][nx+dx[i]][ny+dy[i]]=d[x][y][nx][ny]+1;
				q[f++]=((nx+dx[i])<<8)|(ny+dy[i]);
				}
		b++;
	}
	return;
}
int id(int x,int y)
{
int a,b;
a=ix-x;
b=iy-y;
a<0?a=-a:0;
b<0?b=-b:0;
return a>b?a:b;
}
int main()
{
	int i,j,k;
	while(scanf("%s",c)!=EOF)
	{
		memset(d,0x3f,sizeof(d));
		ans=0x7fffffff;
		l=strlen(c);
		ix=c[0]-'A'+1;
		iy=c[1]-'0';
		j=0;
		for(i=2;i<l;i++)
		{
			a[j]=c[i++]-'A'+1;
			b[j]=c[i]-'0';
			j++;
		}
		n=j;
		for(i=1;i<9;i++)
			for(j=1;j<9;j++)
				bfs(i,j);
		for(x=1;x<9;x++)
			for(y=1;y<9;y++)
				for(k=0;k<n;k++)
				{
					dis=0;
					for(l=0;l<n;l++)
						if(l!=k)
							dis+=d[a[l]][b[l]][x][y];
					for(i=1;i<9;i++)
						for(j=1;j<9;j++)
							if(ans>id(i,j)+d[a[k]][b[k]][i][j]+d[i][j][x][y]+dis)
								ans=id(i,j)+d[a[k]][b[k]][i][j]+d[i][j][x][y]+dis;
				}
		printf("%d\n",ans);
	}
return 0;
}