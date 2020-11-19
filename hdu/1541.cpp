#include<stdio.h>
#include<string.h>
int c[32020];
int v[32020];
int i,j,k;
int n,x,y;
int max(int x,int y)
{
	return x>y?x:y;
}
void R(int x,int v)
{
	for(;x<=32001;x+=x&-x)
		c[x]+=v;
}
int G(int x)
{
	int _=0;
	for(;x;x-=x&-x)
		_+=c[x];
	return _;
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(c,0,sizeof c);
		memset(v,0,sizeof v);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x,&y),x++;
			R(x,1);
			v[G(x)-1]++;
		}
		for(i=0;i<n;i++)
			printf("%d\n",v[i]);
	}
	return 0;
}
