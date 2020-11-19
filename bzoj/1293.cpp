#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct N{int x,c;}a[1000020];
int cnt,v[100];
int i,j,k,t,b,f,n,m,ans;
bool cmp(N a,N b)
{
	return a.x<b.x;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&t);
		for(j=0;j<t;j++)
		{
			scanf("%d",&a[k].x);
			a[k].c=i;
			k++;
		}
	}
	sort(a,a+n,cmp);
	for(b=f=0;f<n;f++)
	{
		if(v[a[f].c]==0)
			cnt++;
		v[a[f].c]++;
		if(cnt==m)
			break;
	}
	ans=a[f].x-a[b].x;
	for(f++;f<n;f++)
	{
		v[a[f].c]++;
		while(v[a[b].c]>1)
		{
			v[a[b].c]--;
			b++;
		}
		ans=min(ans,a[f].x-a[b].x);
	}
	printf("%d",ans);
	return 0;
}