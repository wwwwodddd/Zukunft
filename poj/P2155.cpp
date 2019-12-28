#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[1030][1030];
int ans;
int n,m,x,y,u,v;
int i,j,t;
char o;
int max(int x,int y)
{
	return x>y?x:y;
}
void R(int x,int y,int v)
{
	for(int i=x;i<=n;i+=(i&(-i)))
		for(int j=y;j<=n;j+=(j&(-j)))
			c[i][j]+=v;
}
int G(int x,int y)
{
	int q=0;
	for(int i=x;i>0;i-=(i&(-i)))
		for(int j=y;j>0;j-=(j&(-j)))
			q+=c[i][j];
	return q;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(c,0,sizeof(c));
		scanf("%d %d",&n,&m);
		while(m--)
		{
			scanf("%s",&o);
			if(o=='C')
			{
				scanf("%d %d %d %d",&x,&y,&u,&v);
				u++,v++;
				R(x,y,1);
				R(u,v,1);
				R(x,v,1);
				R(u,y,1);
			}
			else if(o=='Q')
			{
				scanf("%d %d",&x,&y);
				printf("%d\n",G(x,y)&1);
			}
		}
		printf("\n");
	}
	return 0;
}
