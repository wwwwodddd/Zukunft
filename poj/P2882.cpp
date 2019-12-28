#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int v[102][102][102];
int mx,nx,my,ny,mz,nz,x,y,z,b,f,t,n;
int qx[1100020],qy[1100020],qz[1100020];
int in(int x,int y,int z)
{
	return nx<=x&&mx>=x&&ny<=y&&my>=y&&nz<=z&&mz>=z;
}
void bfs(int x,int y,int z)
{
	b=f=0;
	qx[f]=x;
	qy[f]=y;
	qz[f]=z;
	f++;
	while(b<f)
	{
		int xx=qx[b],yy=qy[b],zz=qz[b];
		b++;
		for(int i=0;i<6;i++)
		{
			int px=xx+dx[i];
			int py=yy+dy[i];
			int pz=zz+dz[i];
			if(in(px,py,pz)&&!v[px][py][pz])
			{
				v[px][py][pz]=1;
				qx[f]=px;
				qy[f]=py;
				qz[f]=pz;
				f++;
			}
		}
	}
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		if(n==0)
		{
			puts("0");
			continue;
		}
		memset(v,0,sizeof v);
		mx=my=mz=0x0000;
		nx=ny=nz=0xffff;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			nx=min(nx,x),mx=max(mx,x);
			ny=min(ny,y),my=max(my,y);
			nz=min(nz,z),mz=max(mz,z);
			v[x][y][z]=1;
		}
		mx++,my++,mz++;
		nx--,ny--,nz--;
		int cnt=0;
		for(int i=nx;i<=mx;i++)
			for(int j=ny;j<=my;j++)
				for(int k=nz;k<=mz;k++)
					if(!v[i][j][k])
						cnt++,bfs(i,j,k);
		printf("%d\n",cnt-1);
	}
	return 0;
}
