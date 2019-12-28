#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,x,y;
vector<int>a[10020];
vector<int>b[10020];
map<int,int>g[10020];
int bcc;
int r[10020];
int v[10020];
int u[10020];
int s[10020],ss;
void mk(int x)
{
	fe(i,b[x])
		if(!g[x][*i])
			g[x][*i]=g[*i][x]=1,mk(*i);
	s[ss++]=x;
}
int main()
{
	scanf("%d %d",&n,&m);
	fr(i,m)
	{
		scanf("%d %d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	fo(i,n)
		if(!r[i])
		{
			r[i]=++bcc;
			if(a[i].size()>2)
			{
				fe(j,a[i])
					if(a[*j].size()>2)
						r[*j]=bcc;
			}
			else
				u[bcc]=i;
		}
	fo(i,n)
		fe(j,a[i])
			if(r[i]!=r[*j])
				b[r[i]].push_back(r[*j]);
	fo(i,bcc)
		if(b[i].size()&1)
			return puts("-1");
	mk(1);
	ss--;
	fr(i,ss)
	{
		if(u[s[i]])
			printf("%d ",u[s[i]]);
		else
		{
			int pr=u[s[(i+ss-1)%ss]];
			int nx=u[s[(i+ss+1)%ss]];
			fr(j,2)
				fr(k,2)
					if(r[a[pr][j]]==s[i]&&r[a[nx][k]]==s[i])
						printf("%d %d ",a[pr][j],a[nx][k]);
		}
	}
	return 0;
}
