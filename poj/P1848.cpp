#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int inf=1<<28;
int n,m,k;
vector<int>t[105];
int f[105][3];
void S(int v,int z)
{
	int i,j,k,l;
	int sum=0;
	for(i=0;i<t[v].size();i++)
	{
		j=t[v][i];
		if(j==z)
			continue;
		S(j,v);
		sum+=f[j][0];
	} 
	f[v][1]=sum;
	f[v][0]=f[v][2]=inf;
	for(int i=0;i<t[v].size();i++)
	{
		j=t[v][i];
		if(j==z)
			continue;
		f[v][2]=min(f[v][2],sum-f[j][0]+min(f[j][1],f[j][2]));
		for(int l=i+1;l<t[v].size();l++)
		{
			k=t[v][l];
			if(k==z)
				continue;
			f[v][0]=min(f[v][0],sum-f[j][0]-f[k][0]+min(f[j][1],f[j][2])+min(f[k][1],f[k][2])+1);
		}
		f[v][0]=min(f[v][0],sum-f[j][0]+f[j][2]+1);
	}
}
int main()
{
	while(scanf("%d",&n)+1)
	{
		for(int i=1;i<=n;i++)
			t[i].clear();
		int a,b;
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			t[a].push_back(b);
			t[b].push_back(a);
		}
		S(1,0);
		printf("%d\n",f[1][0]>=inf?-1:f[1][0]);
	}
	return 0;
}
