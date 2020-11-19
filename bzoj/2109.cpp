#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[2020];
vector<int>b[2020];
char g[2020][2020];
int n,m,x,y,v[2020],w[2020];
typedef pair<int,int> ii;
ii p[2020];
void F(int x)
{
	v[x]=-1;
	fe(i,a[x])
	{
		if(!v[*i])
			F(*i);
		w[x]=min(w[x],w[*i]-1);
	}
}
void G(int x,int y)
{
	g[x][y]=1;
	v[y]=x;
	fe(i,b[y])
		if(v[*i]!=x)
			G(x,*i);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",w+i);
	for(int j=0;j<m;j++)
		scanf("%d %d",&x,&y),a[x].push_back(y),b[y].push_back(x);
	for(int i=1;i<=n;i++)
		if(!v[i])
			F(i);
	for(int i=1;i<=n;i++)
		G(i,i);
	for(int i=1;i<=n;i++)
		p[i]=ii(w[i],i);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		int z=n;
		for(int j=n;j;j--)
			if(!g[i][p[j].second]&&p[j].first>=z)
				z--;
		printf("%d%c",z,i<n?' ':'\n');
	}
	return 0;
}
