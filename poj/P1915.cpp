#include<stdio.h>
#include<string.h>
int q[100000];
int t[300][300];
int l,sx,sy,ex,ey,n;
int nx,ny,nd;
int b,f,r;
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
void in(int fx,int fy,int fd)
{
if(fx<0||fy<0||fx>=l||fy>=l)
return;
if(t[fx][fy]<=fd)
return;
q[f++]=(fd<<20)|(fx<<10)|fy;
t[fx][fy]=fd;
if(t[ex][ey]!=9999)
	{
	printf("%d\n",t[ex][ey]);
	r=1;
	}
}
int main()
{
int i,j,k;
scanf("%d",&n);
while(n--)
{
r=0;
memset(q,0,sizeof(q));
memset(t,0,sizeof(t));
scanf("%d %d %d %d %d",&l,&sx,&sy,&ex,&ey);
for(i=0;i<l;i++)
	for(j=0;j<l;j++)
		t[i][j]=9999;
t[sx][sy]=0;
q[0]=(sx<<10)|sy;
b=0;
f=1;
while(b<f)	
{
ny=(q[b]&0x000003ff);
nx=(q[b]&0x000ffc00)>>10;
nd=(q[b]&0xfff00000)>>20;
for(i=0;i<8;i++)
	{
	in(nx+dx[i],ny+dy[i],nd+1);
	if(r==1)
		goto end;
	}
b++;
}
end:;
}
return 0;	
}
