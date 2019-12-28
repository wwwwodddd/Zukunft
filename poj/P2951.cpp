#include<stdio.h>
#include<iostream>
using namespace std;
int f[25][25][25];
int x,y,z;
int F(int x,int y,int z)
{
	if(z==1)
		return x*y;
	if(f[x][y][z])
		return f[x][y][z];
	if(f[y][x][z])
		return f[y][x][z];
	int re=x*y;
	for(int i=1;i<x;i++)
		for(int j=1;j<z;j++)
			re=min(re,max(F(x-i,y,j),F(i,y,z-j)));
	for(int i=1;i<y;i++)
		for(int j=1;j<z;j++)
			re=min(re,max(F(x,y-i,j),F(x,i,z-j)));
	return f[x][y][z]=re;
}
int main()
{
	while(scanf("%d %d %d",&x,&y,&z)&&x+y+z)
		printf("%d\n",F(x,y,z));
	return 0;
}