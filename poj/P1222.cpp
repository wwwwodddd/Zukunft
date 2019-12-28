#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
int q[40][40];
int dx[5]={0,0,1,-1,0};
int dy[5]={1,-1,0,0,0};
int n,m,Case;
int ans[40];
void solve()
{
	int i,j,k,t;
	int r=0,c=0,a,b,cnt=0;
	while(r<30&&c<30)
	{
		int id=r;
		for(i=r+1;i<30;i++)
			if(abs(q[i][c])>abs(q[id][c]))
				id=i;
		if(q[id][c])
		{
			for(i=c;i<=30;i++)
				std::swap(q[id][i],q[r][i]);
			for(i=r+1;i<30;i++)
				if(q[i][c])
					for(j=c;j<=30;j++)
						q[i][j]^=q[r][j];
			r++;
		}
		c++;
	}
	for(i=29;i>=0;i--)
	{
		for(j=i+1;j<30;j++)
			q[i][30]^=(q[i][j]&q[j][30]);
		ans[i]=q[i][30];
	}
	printf("PUZZLE #%d\n",++Case);
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
			printf("%d ",ans[i*6+j]);
		printf("\n");
	}
	return;
}
int main()
{	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,k;
		int x,y,a,b;
		memset(q,0,sizeof(q));
		for(i=0;i<5;i++)
			for(j=0;j<6;j++)
			{
				a=i*6+j;
				scanf("%d",&q[a][30]);
				for(k=0;k<5;k++)
				{
					x=i+dx[k];
					y=j+dy[k];
					if(x>=0&&x<5&&y>=0&&y<6)
						q[a][x*6+y]=1;
				}
			}
		solve();
	}
	return 0;
}