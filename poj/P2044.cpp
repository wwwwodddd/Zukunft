#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int q[100000];
int a[366][4][4];
char t[8][8][8][8][9][365];
int dx[9]={0,0,0,0,1,2,-1,-2,0};
int dy[9]={1,2,-1,-2,0,0,0,0,0};
int i,j,k,b,f;
int n,nx,ny,nd,nz,r;
void in(int fx,int fy,int fd,int fz)
{
int za,zb,zc,zd;
if(fx<0||fy<0||fx>2||fy>2)
	return;
fz+=0x00001111;
if(fx==0&&fy==0)
	fz&=0xffff0fff;
if(fx==0&&fy==2)
	fz&=0xfffff0ff;
if(fx==2&&fy==0)
	fz&=0xffffff0f;
if(fx==2&&fy==2)
	fz&=0xfffffff0;
za=(fz&0x0000f000)>>12;
zb=(fz&0x00000f00)>>8;
zc=(fz&0x000000f0)>>4;
zd=(fz&0x0000000f);
if(t[za][zb][zc][zd][3*fx+fy][fd]==1)
	return;
if(a[fd][fx][fy]||a[fd][fx][fy+1]||a[fd][fx+1][fy]||a[fd][fx+1][fy+1])
	return;
if(za>6||zb>6||zc>6||zd>6)
	return;
if(fd==n)
	{
	printf("1\n");
	r=1;
	return;
	}
t[za][zb][zc][zd][3*fx+fy][fd]=1;
q[f]=((fz)<<16)|(fx)<<14|(fy)<<12|fd;
f++;
if(f==100000)
f=0;
}
int main()
{
while(1)
{
r=0;
scanf("%d",&n);
if(n==0)
break;
memset(q,0,sizeof(q));
memset(a,0,sizeof(a));
memset(t,0,sizeof(t));
for(i=1;i<=n;i++)
	for(j=0;j<4;j++)
		for(k=0;k<4;k++)
			scanf("%d",&a[i][j][k]);
b=0;
f=1;
q[0]=0x11115001;
if((a[1][1][1]==1)||(a[1][1][2]==1)||(a[1][2][1]==1)||(a[1][2][2]==1))
b=f;
while(b!=f)
{
nz=(q[b]&0xffff0000)>>16;
nx=(q[b]&0x0000c000)>>14;
ny=(q[b]&0x00003000)>>12;
nd=q[b]&0x00000fff;
//printf("x:%3d y:%3d z:%08x d:%3d\n",nx,ny,nz,nd);
for(i=0;i<9;i++)
	{
	in(nx+dx[i],ny+dy[i],nd+1,nz);
	if(r==1)
	goto END;
	}
b!=99999?b++:b=0;
}
printf("0\n");
END:;
}
return 0;
}
