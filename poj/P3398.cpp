#include<stdio.h>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,x,y;
vector<int>a[10020];
int f[10020][3];
void dfs(int x,int y)
{
	f[x][0]=1;
	f[x][1]=0xffffff;
	f[x][2]=0;
	fe(i,a[x])
		if(*i!=y)
		{
			dfs(*i,x);
			f[x][0]+=min(f[*i][0],f[*i][2]);
			f[x][1]=min(f[x][1],-f[*i][1]+f[*i][0]);
			f[x][2]+=f[*i][1];
		}
	f[x][1]+=f[x][2];
}
int main()
{
	while(1)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1,0);
		printf("%d\n",min(f[1][0],f[1][1]));
		scanf("%d",&n);
		if(n==-1)
			break;
	}
	return 0; 
}
