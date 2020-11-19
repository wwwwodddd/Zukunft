#include<stdio.h>
#include<string.h>
int c[100020];
int n,x,z,k;
void R(int x,int y)
{
	for(;x;x-=x&-x)
		c[x]+=y;
}
int G(int x)
{
	int re=0;
	for(;x<=n*n;x+=x&-x)
		re+=c[x];
	return re;
}
int main()
{
	for(;scanf("%d",&n),n;)
	{
		memset(c,0,sizeof c);
		z=k=0;
		for(int i=n*n;i--;)
		{
			scanf("%d",&x);
			if(x)
				z+=G(x),R(x,1);
			else
				k=i/n;
		}
		if(~n&1)
			z+=k;
		puts(z&1?"NO":"YES");
	}
}
