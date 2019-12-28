#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int n,m,b,f;
int a[5020];
vector<int>v[5020];
set<int>s[5020];
struct N
{
	int e,x,d;
	N(int e=0,int x=0,int d=0):e(e),x(x),d(d){}
}p,q[500020];
int bfs()
{
	int i,j,k,d,x;
	b=f=0;
	q[f++]=N(1,a[1],0);
	s[1].insert(a[1]);
	while(b<f)
	{
		p=q[b++];
		i=p.e;d=p.d;
		for(j=0;j<v[i].size();j++)
		{
			k=v[i][j];
			x=a[i]-a[k];
			if(x>180)
				x-=360;
			if(x<-180)
				x+=360;
			x+=p.x;
			if(s[k].find(x)==s[k].end())
			{
				if(k==1)
					return d+1;
				q[f++]=N(k,x,d+1);
				s[k].insert(x);
			}
		}
	}
	return -1;
}
int main()
{
	int i,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	printf("%d\n",bfs());
	return 0;
}