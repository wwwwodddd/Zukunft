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
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int> ii;
priority_queue<ii,vector<ii>,greater<ii> >q;
vector<ii>a[100];
int d[5020],v[5020];
int x,y,z,k,n,m;
void dijk()
{
	memset(d,0x3f,sizeof d);
	d[1]=0;
	q.push(ii(0,1));
	while(q.size())
	{
		ii u=q.top();
		q.pop();
		if(v[u.Y])
			continue;
		v[u.Y]=1;
		x=(u.Y-1)%n+1;
		y=u.Y-x;
		z=y/n;
		fe(j,a[x])
			if(d[y+j->X]>d[u.Y]+j->Y)
			{
				d[y+j->X]=d[u.Y]+j->Y;
				q.push(ii(d[y+j->X],y+j->X));
			}
		if(z<k)
			fe(j,a[x])
				if(d[y+j->X+n]>d[u.Y]+j->Y/2)
				{
					d[y+j->X+n]=d[u.Y]+j->Y/2;
					q.push(ii(d[y+j->X+n],y+j->X+n));
				}
	}
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		a[x].push_back(ii(y,z));
		a[y].push_back(ii(x,z));
	}
	int ans=0x3f3f3f3f;
	dijk();
	for(int i=1;i<=k+1;i++)
		ans=min(ans,d[i*n]);
	printf("%d\n",ans);
	return 0;
}
