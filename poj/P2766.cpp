#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,r,x,y,d;
int v[60][60];
int a[60][60];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int in(int x,int y)
{
	return x>0&&y>0&&x<=n&&y<=n;
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d %d",&n,&r);
		memset(a,0,sizeof a);
		for(int i=0;i<r;i++)
			scanf("%d %d",&x,&y),a[x][y]=1;
		scanf("%d %d",&x,&y);
		if(x==0)
			d=0;
		else if(y==n+1)
			d=1;
		else if(x==n+1)
			d=2;
		else if(y==0)
			d=3;
		memset(v,0,sizeof v);
		while(1)
		{
			x+=dx[d];
			y+=dy[d];
			if(!in(x,y))
			{
				printf("%d %d\n",x,y);
				goto end;
			}
			if(v[x][y]>>d&1)
				break;
			v[x][y]|=1<<d;
			if(a[x][y])
				++d&=3;
		}
		puts("0 0");
		end:;
	}
}