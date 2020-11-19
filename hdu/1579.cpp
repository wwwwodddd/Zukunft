#include<stdio.h>
int a[21][21][21];
int w(int x,int y,int z)
{
	if(x<=0||y<=0||z<=0)
		return 1;
	else if(x>20||y>20||z>20)
		return w(20,20,20);
	else if(a[x][y][z]!=0)
		return a[x][y][z];
	else if(x<y&&y<z)
		return a[x][y][z]=w(x,y,z-1)+w(x,y-1,z-1)-w(x,y-1,z);
	else
		return a[x][y][z]=w(x-1,y,z)+w(x-1,y-1,z)+w(x-1,y,z-1)-w(x-1,y-1,z-1);
}
int main()
{
	int i,j,k,x,y,z;
	while(scanf("%d%d%d",&x,&y,&z)&&!(x==-1&&y==-1&&z==-1))
		printf("w(%d, %d, %d) = %d\n",x,y,z,w(x,y,z));
	return 0;
}