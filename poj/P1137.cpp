#include<stdio.h>
#include<string.h>
int q[1000000];
int m[20][20];
int c[20][20];
int b,f,nx,nd;
int t[11][1024];
int r,d,s,n,cas;
void in(int fx,int fd)
{
if(t[fx][fd]!=0)
	return;
t[fx][fd]=(nx<<16)|nd;
q[f++]=(fx<<16)|fd;
return;
}
int dfs(int fx,int fd)
{
if(fx==1&&fd==1)
	return 0;
int sx,sd;
sx=t[fx][fd]>>16;
sd=t[fx][fd]&0x0000ffff;
return 1+dfs(sx,sd);
}
void print(int fx,int fd)
{
if(fx==1&&fd==1)
	return;
int sx,sd,w=1,k;
sx=t[fx][fd]>>16;
sd=t[fx][fd]&0x0000ffff;
k=fd^sd;
while(k>1)
	k>>=1,w++;
print(sx,sd);
if(fx!=sx)
	printf("- Move to room %d.\n",fx);
else if(fd>sd)
	printf("- Switch on light in room %d.\n",w);
else
	printf("- Switch off light in room %d.\n",w);
}
int main()
{
int i,j;
freopen("C:\\c.in","r",stdin);
freopen("C:\\c1.out","w",stdout);
while(scanf("%d %d %d",&r,&d,&s)&&r!=0)
{
memset(t,0,sizeof(t));
memset(m,0,sizeof(m));
memset(c,0,sizeof(c));
while(d--)
{
scanf("%d %d",&i,&j);
m[i][j]=1;
m[j][i]=1;
}
while(s--)
{
scanf("%d %d",&i,&j);
c[i][j]=1;
}
b=0;
f=1;
q[0]=0x00010001;
while(b<f)
{
nx=(q[b]&0xffff0000)>>16;
nd=(q[b]&0x0000ffff);
i=1;
for(i=1;i<=r;i++)
	if(m[nx][i]&&((nd>>(i-1))&1)==1)
		in(i,nd);
for(i=1;i<=r;i++)
	{
	if((nd>>(i-1)&1)==0&&c[nx][i])
		in(nx,nd|(1<<(i-1)));
	if((nd>>(i-1)&1)==1&&c[nx][i]&&i!=nx)
		in(nx,nd&(~(1<<(i-1))));
	}
b++;
}
printf("Villa #%d\n",++cas);
if(t[r][1<<(r-1)]||r==1)
{
printf("The problem can be solved in %d steps:\n",dfs(r,1<<(r-1)));
print(r,1<<(r-1));
printf("\n");
}
else
printf("The problem cannot be solved.\n\n");
}
return 0;
}
