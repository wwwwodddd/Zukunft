#include<iostream>
#include<vector>
using namespace std;
int n,m;
struct P
{
	int x,y,c;
}p[1010];
vector<int>g[1010];
int f[1010][2],t[1010];
void dfs(int v)
{
	t[v]=1;
	f[v][0]=0,f[v][1]=p[v].c;
	int j;
	for(int i=0;i<g[v].size();i++)
		if(!t[g[v][i]])
		{
			j=g[v][i];
			dfs(j);
			f[v][0]=max(f[v][0],max(f[j][0],f[j][1]));
			if(f[j][1]>0)
				f[v][1]+=f[j][1];
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].c);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)==1)
			{
				g[i].push_back(j);
				g[j].push_back(i);
			}
	dfs(0);
	printf("%d\n",max(f[0][0],f[0][1]));
	return 0;
}