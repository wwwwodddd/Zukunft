#include<stdio.h>
#include<string.h>
#include<iostream>
#include<map>
#define X first
#define Y second
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
map<int,int>f,g;
int a[10020],c,b[120],n,m,x,z;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=z=c=0;i<1<<m;i++)
			if((i&i<<2)==0)
				a[c++]=i;
		memset(b,0,sizeof b);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&x),b[i]|=!x<<j;
		f.clear();
		f[0]=0;
		for(int i=0;i<n;i++)
		{
			g.clear();
			fe(j,f)
			{
				int h=j->X>>m,l=j->X&(1<<m)-1;
				for(int k=0;k<c;k++)
				{
					if(!(a[k]&b[i])&&!(a[k]&l)&&!(a[k]&h>>1)&&!(a[k]&h<<1))
					{
						int u=a[k]<<m|h,w=max(g[u],j->Y+__builtin_popcount(a[k]));
						g[u]=max(g[u],w);
						z=max(z,w);
					}
				}
			}
			f.swap(g);
		}
		printf("%d\n",z);
	}
	return 0;
}
