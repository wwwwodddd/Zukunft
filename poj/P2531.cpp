#include<iostream>
using namespace std;
int g[22][22],v[22];
int n,ans,sum;
void dfs(int t)
{
	if(t==n)
	{
		if(sum>ans)
			ans=sum;
		return;
	}
	v[t]=0;
	int z=0;
	for(int i=0;i<t;i++)
			if(v[i]==1)
					z+=g[t][i];
	sum+=z;
	dfs(t+1);
	sum-=z;
	z=0;
	v[t]=1;
	for(int i=0;i<t;i++)
		if(v[i]==0)
			z+=g[t][i];
	sum+=z;
	dfs(t+1);
	sum-=z;
}
int main()
{
	int i,j ;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>g[i][j];
	dfs(1);
	cout<<ans<<endl;
}