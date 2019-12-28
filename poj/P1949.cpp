#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define F(x,k) for(x=1;x<=k;x++)
int i,j,k,mx,n,m,t;
int c[10005];
int main()
{
	scanf("%d",&n);
	F(i,n)
	{
		scanf("%d %d",&c[i],&m);
		mx=0;
		while(m--)
		{
			scanf("%d",&k);
			mx=max(c[k],mx);
		}
		c[i]+=mx;
		t=max(c[i],t);
	}
	printf("%d\n",t);
	return 0;
}
