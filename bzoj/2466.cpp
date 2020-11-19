#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,x,y;
vector<int>a[120];
int f[120][3];
void F(int x,int y)
{
	f[x][0]=1;
	int mn=0xffffff,s=0,t=0;
	fe(i,a[x])
		if(*i!=y)
		{
			F(*i,x);
			f[x][0]+=f[*i][2];
			mn=min(mn,abs(f[*i][0]-f[*i][1]));
			s+=min(f[*i][0],f[*i][1]);
			t^=f[*i][0]<f[*i][1];
		}
	f[x][2-t]=s;
	f[x][1+t]=s+mn;
}
int main()
{
	while(scanf("%d",&n),n)
	{
		for(int i=1;i<=n;i++)
			a[i].clear();
		memset(f,0,sizeof f);
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		F(1,0);
		printf("%d\n",min(f[1][0],f[1][1]));
	}
}
