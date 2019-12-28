#include<iostream>
#include<algorithm>
using namespace std;
struct N{int x,w,f,c;}g[10020];
int f[1020][1020];
int l,n,b,i,j;
int cmp(N a,N b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%d%d%d",&l,&n,&b);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&g[i].x,&g[i].w,&g[i].f,&g[i].c);
	memset(f,-1,sizeof(f));
	for(i=0;i<=b;i++)
		f[0][i]=0;
	sort(g,g+n,cmp);
	for(i=0;i<n;i++)
		for(j=b;j>=g[i].c;j--)
			if(f[g[i].x][j-g[i].c]!=-1)
				f[g[i].x+g[i].w][j]=max(f[g[i].x][j-g[i].c]+g[i].f,f[g[i].x+g[i].w][j]);
	printf("%d\n",f[l][b]);
	return 0;
}