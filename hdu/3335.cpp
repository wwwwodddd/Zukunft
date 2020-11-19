#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
using namespace std;
vector<int>b[1020];
long long a[1020];
int t,n,z,v[1020],l[1020];
int dfs(int x)
{
	fe(i,b[x])
		if(!v[*i])
		{
			v[*i]=1;
			if(l[*i]==-1||dfs(l[*i]))
				return l[*i]=x,1;
		}
	return 0;
}
int main()
{
	for(scanf("%d",&t);t--;)
	{
		z=0;
		memset(l,-1,sizeof l);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%I64d",a+i);
		sort(a,a+n);
		n=unique(a,a+n)-a;
		for(int i=0;i<n;i++)
			b[i].clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j)
					if(a[i]%a[j]==0)
						b[i].push_back(j);
		for(int i=0;i<n;i++)
		{
			memset(v,0,sizeof v);
			if(!dfs(i))
				z++;
		}
		printf("%d\n",z);
	}
	return 0;
}
