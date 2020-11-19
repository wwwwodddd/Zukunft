#include<stdio.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
int n,t,z,c,s,x,y;
int F(int x,int y)
{
	int z=0;
	fe(i,a[x])
		if(*i!=y)
			z^=1+F(*i,x);
	return z;
}
int main()
{
	for(;~scanf("%d",&t);)
	{
		for(c=z=0;t--;)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				a[i].clear();
			for(int i=1;i<n;i++)
			{
				scanf("%d%d",&x,&y);
				a[x].push_back(y);
				a[y].push_back(x);
			}
			z^=s=F(1,0);
			if(s>1)
				c++;
		}
		puts(!!z^!!c?"QQ":"PP");
	}
	return 0;
}
