#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m;
short a[1020][1020];
int in[1020];
int v[1020];
int q[1020],f;
int x,y;
int main()
{
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	while(scanf("%d %d",&n,&m),n+m)
	{
		n*=2;
		fo(i,n)
			fo(j,n)
				if(i!=j)
					a[i][j]=1;
		fo(i,n)
			in[i]=n-1;
		fr(i,m)
		{
			scanf("%d %d",&x,&y);
			a[x][y]=a[y][x]=0;
			in[x]--;
			in[y]--;
		}
		int x=1,p;
		while(1)
		{
			q[f++]=x;
			v[x]=1;
			p=0;
			fo(i,n)
				if(a[x][i]&&!v[i])
				{
					in[i]--;
					if(!p||in[i]<in[p]||in[i]==in[p]&&a[i][1]==0)
						p=i;
				}
			if(!p)
				break;
			x=p;
		}
		fr(i,f)
			printf("%d ",q[i]);
		memset(in,0,sizeof in);
		memset(v,0,sizeof v);
		fo(i,n)
			fo(j,n)
				a[i][j]=0;
		f=0;
		puts("");
	}
}
