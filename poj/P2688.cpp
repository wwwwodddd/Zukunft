#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int d[30][30][2050];
int t[30][30][2050];
int m[30][30];
int q[1000000];
int n,l,x,b,f,p,sum,tar,r,xd;
char c;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int nx,ny,nd,i,j,k,ans=2147483647;
void in(int fx,int fy,int fd)
{
if(fx>=0&&fy>=0&&fx<l&&fy<n)
		{
		if(m[fx][fy]!=999&&d[fx][fy][fd]>d[nx][ny][nd]+1)
			{
				if(t[fx][fy][nd]==p)
					return;
				d[fx][fy][nd]=d[nx][ny][nd]+1;
				xd=nd;
				if(m[fx][fy]>0)
					{
					xd|=(1<<(m[fx][fy]-1));
					d[fx][fy][xd]=d[nx][ny][nd]+1;
					if(xd==tar)
						{
						printf("%d\n",d[fx][fy][tar]);
						sum+=b;
						r=1;
						return;
						}
					}
				if(t[fx][fy][xd]==p)
					return;
				t[fx][fy][xd]=p;
				q[f++]=(xd<<16)|(fy<<8)|fx;
			}
		
		}

}
int main()
{
//freopen("C:\\cc.in","w",stdout);
freopen("C:\\c.out","r",stdin);
while(scanf("%d %d",&n,&l)&&n!=0&&l!=0)
{
p++;
ans=2147483647;
q[0]=0;
getchar();
x=1;
r=0;
for(i=0;i<l;i++)
	for(j=0;j<n;j++)
		for(k=0;k<2049;k++)
			d[i][j][k]=999;
for(i=0;i<l;i++)
	{
	for(j=0;j<n;j++)
		{
		scanf("%c",&c);
		if(c=='x')
			m[i][j]=999;
		else if(c=='.')
			m[i][j]=0;
		else if(c=='*')
			m[i][j]=x++;
		else if(c=='o')
			{
			m[i][j]=0;
			d[i][j][0]=0;
			q[0]=i|(j<<8);
			t[i][j][0]=1;
			}
		}
	getchar();
	}
tar=(1<<(x-1))-1;
b=0;
f=1;
while(b<f)
	{
	nx=q[b]&0x000000ff;
	ny=(q[b]&0x0000ff00)>>8;
	nd=(q[b]&0xffff0000)>>16;
	//t[nx][ny][nd]=0;
	for(i=0;i<4;i++)
		in(nx+dx[i],ny+dy[i],nd);
	if(r==1)
		goto end;
	b++;
	}
printf("-1\n");
end:;
}
//printf("------%d",sum);
return 0;
}


