#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int nx[100020];
int pr[100020];
int n,m;
vector<int>a[100020];
void dfs(int x)
{
	for(;;)
	{
		printf("%d\n",x);
		nx[pr[x]]=nx[x];
		pr[nx[x]]=pr[x];
		vector<int>&t=a[x];
		sort(t.begin(),t.end());
		int j,k=0;
		for(j=nx[0];j<=n;j=nx[j])
		{
			while(k<t.size()&&j>t[k])
				k++;
			if(k==t.size()||j<t[k])
				break;
		}
		if(j>n)
			return;
		x=j;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		nx[i]=i+1,pr[i]=i-1;
	nx[0]=1;
	pr[n+1]=n;
	while(m--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	return 0;
}
