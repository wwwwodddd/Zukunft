#include<stdio.h>
int m[100][100];
int c[100][100];
int l,n,x,max;
int i,j,k,ct;
void check(int d,int x,int y)
{
if(d&1)
if(d&2)
if(d&4)
if(d&8)
return;
}
int dfs(int x,int y)
{
int d1=0,d2=0,d3=0,d4=0;
if(m[x][y]||x<1||x>n||y<1||y>l)
	return 0;
m[x][y]=1;
if(!(c[x][y]&1))
	d1=dfs(x,y-1);
if(!(c[x][y]&2))
	d2=dfs(x-1,y);
if(!(c[x][y]&4))
	d3=dfs(x,y+1);
if(!(c[x][y]&8))
	d4=dfs(x+1,y);
return 1+d1+d2+d3+d4;
}
int main()
{
scanf("%d %d",&n,&l);
for(i=1;i<=n;i++)
	for(j=1;j<=l;j++)
		scanf("%d",&c[i][j]);
for(i=1;i<=n;i++)
	for(j=1;j<=l;j++)
		{
		x=dfs(i,j);
		if(x!=0)
			ct++;
		if(x>max)
			max=x;
		}
printf("%d\n%d\n",ct,max);
return 0;
}