#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
int F(int x)
{
	int re=0;
	fe(i,a[x])
		re^=F(*i)+1;
	return re;
}
int main()
{
	int x,n,z;
	for(;scanf("%d",&n)+1;)
	{
		z=0;
		for(int i=0;i<=n;i++)
			a[i].clear();
		for(int i=0;i<n;i++)
			scanf("%d",&x),a[x<0?n:x].push_back(i);	
		fe(i,a[n])
			z^=F(*i);
		puts(z?"YES":"NO");
	}
	return 0;
}
