#include<stdio.h>
#include<string.h>
char g[205][205];
char s[205];
int t,k;
char S(int x,int y);
char A(int x,int y)
{
	return x==y;
}
char E(int x,int y)
{
	if(g[x][y]>=0)
		return g[x][y];
	return g[x][y]=A(x,y)|S(x,y);
}
char L(int x,int y)
{
	int i;
	if(g[x][y]>=0)
		return g[x][y];
	if(E(x,y))
		return g[x][y]=1;
	for(i=x;i<=y;i++)
		if(s[i]==','&&E(x,i-1)&&L(i+1,y))
			return g[x][y]=1;
	return g[x][y]=0;
}
char EL(int x,int y)
{
	if(g[x][y]>=0)
		return g[x][y];
	if(x==y+1)
		return g[x][y]=1;
	return g[x][y]=L(x,y);
}
char S(int x,int y)
{
	if(y-x<1)
		return g[x][y]=0;
	if(g[x][y]>=0)
		return g[x][y];
	if(s[x]=='{'&&s[y]=='}')
		return g[x][y]=EL(x+1,y-1);
	return g[x][y]=0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(g,-1,sizeof(g));
		scanf("%s",s);
		printf("Word #%d: %s\n",++k,S(0,strlen(s)-1)?"Set":"No Set");
	}
	return 0;
}