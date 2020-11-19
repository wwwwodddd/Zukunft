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
int f[100020];
int l[100020];
int r[100020];
int d[100020];
int h[100020];
int w[100020];
int s[100020];
int k[100020];
int v[100020];
int u[100020];
int n,m;
long long ans;
int mg(int x,int y)
{
	if(!x||!y)
		return x+y;
	if(w[x]<w[y])
		swap(x,y);
	r[x]=mg(r[x],y);
	if(h[l[x]]<h[r[x]])
		swap(l[x],r[x]);
	h[x]=h[r[x]]+1;
	s[x]=s[l[x]]+s[r[x]]+1;
	u[x]=u[l[x]]+u[r[x]]+w[x];
	return x;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",f+i,w+i,k+i),s[v[i]=i]=1,u[i]=w[i];
	for(int i=n;i;i--)
	{
		ans=max(ans,(long long)s[v[i]]*k[i]);
		v[f[i]]=mg(v[f[i]],v[i]);
		while(u[v[f[i]]]>m)
			v[f[i]]=mg(l[v[f[i]]],r[v[f[i]]]);
	}
	printf("%lld",ans);
	return 0;
}
