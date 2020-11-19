#include<stdio.h>
int f[30020];
int s[30020];
int c[30020];
int F(int x)
{
	if(f[x]==x)
		return x;
	int fx=F(f[x]);
	s[x]+=s[f[x]];
	return f[x]=fx;
}
void U(int x,int y)
{
	x=F(x);
	y=F(y);
	if(x==y)
		return;
	s[y]+=c[x];
	c[x]+=c[y];
	f[y]=x;
}
char o[6];
int t,x,y;
int main()
{
	for(int i=0;i<=30000;i++)
		c[f[i]=i]=1;
	for(scanf("%d",&t);t--;)
	{
		scanf("%s %d",o,&x);
		if(*o=='M')
			scanf("%d",&y),U(y,x);
		else
			printf("%d\n",(F(x),s[x]));
	}
	return 0;
}
