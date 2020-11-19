#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
int F(int x,int y)
{
	int re=0;
	fe(i,a[x])
		if(*i!=y)
			re^=F(*i,x)+1;
	return re;
}
int main()
{
	int t,x,y,n;
	for(scanf("%d",&t);t--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d %d",&x,&y),a[x].push_back(y),a[y].push_back(x);
		puts(F(1,0)?"Alice":"Bob");
	}
	return 0;
}
