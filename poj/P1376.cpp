#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<cmath>
using namespace std;
int s[100][100];
int d[100][100][5];
int t[100][100][5];
int q[10020][3];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
int m,n,sx,sy,ex,ey,nx,ny,nd;
char qwe[10];
int i,j,k,b,f,re;
while(1)
{
scanf("%d %d",&m,&n);
if(m==0&&n==0)
	break;
memset(s,0,sizeof(s));
memset(d,0,sizeof(d));
memset(t,0,sizeof(t));
memset(q,0,sizeof(q));
memset(qwe,0,sizeof(qwe));
for(i=0;i<m;i++)
	for(j=0;j<n;j++)
		{
		scanf("%d",&k);
		if(k==1)
			{
			s[i][j]=1;
			s[i+1][j]=1;
			s[i][j+1]=1;
			s[i+1][j+1]=1;
			}
		}
for(i=0;i<=m;i++)
	s[i][0]=1,s[i][n]=1;
for(j=0;j<=n;j++)
	s[0][j]=1,s[m][j]=1;
scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
scanf("%s",qwe);
q[0][1]=sx;
q[0][2]=sy;
if(strcmp(qwe,"south")==0)
	q[0][0]=1;
else if(strcmp(qwe,"west")==0)
	q[0][0]=2;
else if(strcmp(qwe,"north")==0)
	q[0][0]=3;
else if(strcmp(qwe,"east")==0)
	q[0][0]=0;
b=0;
f=1;
for(i=0;i<=m;i++)
	for(j=0;j<=n;j++)
		for(k=0;k<4;k++)
			d[i][j][k]=2147483647;
d[q[0][1]][q[0][2]][q[0][0]]=0;
t[q[0][1]][q[0][2]][q[0][0]]=1;
while(b<f)
{
nx=q[b][1];
ny=q[b][2];
nd=q[b][0];
t[nx][ny][nd]=0;
if(d[nx][ny][(nd+1)%4]>d[nx][ny][nd]+1)
{
d[nx][ny][(nd+1)%4]=d[nx][ny][nd]+1;
if(t[nx][ny][(nd+1)%4]==0)
{
q[f][0]=(nd+1)%4;
q[f][1]=nx;
q[f][2]=ny;
f++;
}
}
if(d[nx][ny][(nd+3)%4]>d[nx][ny][nd]+1)
{
d[nx][ny][(nd+3)%4]=d[nx][ny][nd]+1;
if(t[nx][ny][(nd+3)%4]==0)
{
q[f][0]=(nd+3)%4;
q[f][1]=nx;
q[f][2]=ny;
f++;
}
}
for(i=1;i<=3;i++)
		if(s[nx+dx[nd]*i][ny+dy[nd]*i]==0)
		{
			if(d[nx+dx[nd]*i][ny+dy[nd]*i][nd]>d[nx][ny][nd]+1)
			{
			d[nx+dx[nd]*i][ny+dy[nd]*i][nd]=d[nx][ny][nd]+1;
			if(t[nx+dx[nd]*i][ny+dy[nd]*i][nd]==0)
				{
				q[f][0]=nd;
				q[f][1]=nx+dx[nd]*i;
				q[f][2]=ny+dy[nd]*i;
				f++;
				}
			}
		}
		else if(s[nx+dx[nd]*i][ny+dy[nd]*i]==1)
			break;
b++;
}
re=min(min(d[ex][ey][0],d[ex][ey][1]),min(d[ex][ey][2],d[ex][ey][3]));
if(re==2147483647)
printf("-1\n");
else
printf("%d\n",re);
}
return 0;
}