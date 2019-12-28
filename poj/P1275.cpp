#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int> ii;
queue<int>q;
vector<ii>a[30];
int t[30],r[30],n,x;
int d[30],v[30],c[30];
int ok(int x)
{
	for(int i=0;i<25;i++)
		a[i].clear();
	for(int i=1;i<25;i++)
	{
		a[i].push_back(ii(i-1,0));
		a[i-1].push_back(ii(i,t[i]));
	}
	for(int i=1;i<9;i++)
		a[i].push_back(ii(i+16,x-r[i]));
	for(int i=9;i<25;i++)
		a[i].push_back(ii(i-8,-r[i]));
	a[24].push_back(ii(0,-x));
	memset(d,0x3f,sizeof d);
	memset(v,0,sizeof v);
	memset(c,0,sizeof c);
	q.push(0);
	d[0]=0;
	while(q.size())
	{
		int u=q.front();
		v[u]=0;
		q.pop();
		fe(i,a[u])
			if(d[i->X]>d[u]+i->Y)
			{
				d[i->X]=d[u]+i->Y;
				c[i->X]=c[u]+1;
				if(c[i->X]>=25)
					return 0;
				if(!v[i->X])
				{
					q.push(i->X);
					v[i->X]=1;
				}
			}
	}
	return 1;
}
void work()
{
	for(int i=1;i<25;i++)
		scanf("%d",r+i);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&x),t[x+1]++;	
	int l=0,r=n+1;
	while(l<r)
		if(ok((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	if(l==n+1)
		puts("No Solution");
	else
		printf("%d\n",l);
}
int main()
{
	int t;
	for(scanf("%d",&t);t--;)
		work();
	return 0;
}
