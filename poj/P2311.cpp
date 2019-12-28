#include<stdio.h>
#include<string.h>
#include<math.h>
int sg[210][210],x,y;
int SG(int x,int y)
{
	if(x>y)
		return SG(y,x);
	if(sg[x][y]!=-1)
		return sg[x][y];
	if(x==1||y==1)
		return sg[x][y]=1;
	if(x<4&&y<4)
		return sg[x][y]=0;
	int j;
	int u[1000];
	memset(u,0,sizeof(u));
	for(j=2;j<=y/2;j++)
		u[SG(x,j)^SG(x,y-j)]=1;
	for(j=2;j<=x/2;j++)
		u[SG(j,y)^SG(x-j,y)]=1;
	for(j=0;u[j];j++);
	return sg[x][y]=j;
}
int main()
{
	memset(sg,-1,sizeof(sg));
	while(scanf("%d%d",&x,&y)!=EOF)
		printf("%s\n",SG(x,y)?"WIN":"LOSE");
	return 0; 
}

