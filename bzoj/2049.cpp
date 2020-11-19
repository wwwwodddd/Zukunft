#include<stdio.h>
int f[100020],n,m;
char o[20];
int F(int x)
{
	while(x!=f[x])
		x=f[x];
	return x;
}
void R(int x)
{
	int y=f[x],u;
	f[x]=x;
	while(x!=y)
	{
		u=f[y];
		f[y]=x;
		x=y;
		y=u;
	}
}
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		f[i]=i;
	for(i=0;i<m;i++)
	{
		scanf("%s%d%d",o,&x,&y);
		x--;y--;
		if(*o=='Q')
			puts(F(x)==F(y)?"Yes":"No");
		else if(*o=='C')
			R(x),R(y),f[y]=x;
		else if(*o=='D')
			R(x),f[y]=y;
	}
	return 0;
}