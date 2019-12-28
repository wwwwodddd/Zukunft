#include<string.h>
#include<stdio.h>
int f[105][105][105],n,m;
int F(int x,int y,int z)
{
	if(f[x][y][z]!=-1)
	return f[x][y][z];
	if(z==0&&(x==0||y==0))
		return x;
	if(z==0)
		return F(0,0,x);
	for(int i=1;i<=m&&i<=z;i++)
		if(f[x][y][z]<y+x+z-F(y,x+i,z-i))
			f[x][y][z]=y+x+z-F(y,x+i,z-i);
	return f[x][y][z];
}
int main()
{
	while(scanf("%d %d",&n,&m)+1)
	{
		memset(f,-1,sizeof(f));
		printf("%d\n",F(0,0,n));
	}
	return 0;
}
