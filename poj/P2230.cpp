#include<iostream>
#include<vector>
using namespace std;
struct E{int x,y;}z;
vector<E>map[10020];
int n,m,s,e;
void dfs(int x)
{
	for(int i=0;i<map[x].size();i++)
		if(map[x][i].y==0)
		{
			map[x][i].y=1;
			dfs(map[x][i].x);
		}
	printf("%d\n",x);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&s,&e);
		z.x=e;
		map[s].push_back(z);
		z.x=s;
		map[e].push_back(z);
	}
	dfs(1);
	return 0;
}
