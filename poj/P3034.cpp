#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct D{
	int dx,dy,dw;
}s[100];
int n,nn,d,m,k;
int ans,u;
int f[15][50][50];
int g[15][50][50];
bool cmp(D a,D b)
{
	return a.dw<b.dw;
}
int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}
int S(int t,int x,int y,int xx,int yy,int dx,int dy)
{
	int sum = 0;
	for(;x!=xx||y!=yy;x+=dx,y+=dy)
		sum+=g[t][x][y];
	return sum;
}
int main()
{
	int t,i,tt,sum;
	int x,y,xx,yy,dx,dy;
	for(x=-5;x<=5;x++)
		for(y=-5;y<=5;y++)
			if(x*x+y*y<=25)
			{
				s[k].dx=x;
				s[k].dy=y;
				s[k].dw=ceil(sqrt(0.0+x*x+y*y));
				k++;
			}
	sort(s,s+k,cmp);
	while(scanf("%d%d%d",&n,&d,&m)&&n+d+m)
	{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		tt=-1;
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&t);
			g[t][x+d][y+d]=1;
			tt=max(tt,t);
		}
		tt++;
		nn=n+2*d;
		for(t=1;t<tt;t++)
			for(x=0;x<nn;x++)
				for(y=0;y<nn;y++)
					for(i=0;s[i].dw<=d&&i<k;i++)
					{
						dx=s[i].dx;
						dy=s[i].dy;
						xx=x+dx;
						yy=y+dy;
						if(xx>=0&&xx<=nn&&yy>=0&&yy<=nn)
						{
							if(i==0)
								sum=g[t][x][y];
							else
							{
								u=gcd(abs(dx),abs(dy));
								dx=dx/u;
								dy=dy/u;
								sum=g[t][xx][yy]+S(t,x,y,xx,yy,dx,dy);
							}
							f[t+1][xx][yy]=max(f[t+1][xx][yy],f[t][x][y]+sum);
						}
					}
		ans=0;
		for(x=d;x<n+d;x++)
			for(y=d;y<n+d;y++)
					ans=max(ans,f[tt][x][y]);
		printf("%d\n",ans);
	}
	return 0;
}