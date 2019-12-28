#include<iostream>
using namespace std;
#define maxn 100
int n,r,i,p,c;
int f[120],g[120];
void work(int p, int c)
{
	for(i=0;i<c;i++)
		g[i]=f[p+i];
	for(i=p-1;i>0;i--)
		f[i+c]=f[i];
	for(i=0;i<c;i++)
		f[i+1]=g[i];
}
int main()
{
	while(scanf("%d%d",&n,&r)&&n+r)
	{
		for(i=1;i<=n;i++)
			f[i]=n-i+1;
		while(r--)
		{
			scanf("%d %d",&p,&c);
			work(p,c);
		}
		printf("%d\n",f[1]);
	}
	return 0;
}
