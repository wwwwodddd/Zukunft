#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define inf 0x3fffffffffffffLL
int a[120];
int t,g,i,n,z,u,v,k;
long long mn,mx,ans;
long long d[400020];
int main()
{
	scanf("%d %lld %lld",&n,&mn,&mx);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(i=1;i<a[0];i++)
		d[i]=inf;
	queue<int>q;
	q.push(0);
	while(q.size())
	{
		u=q.front();
		q.pop();
		for(i=1;i<n;i++)
		{
			v=(u+a[i])%a[0];
			if(d[v]>d[u]+a[i])
			{
				d[v]=d[u]+a[i];
				q.push(v);
			}	
		}
	}
	for(i=0;i<a[0];i++)
	{
		if(d[i]>mx)
			;
		else if(d[i]<=mn)
			ans+=(mx-i)/a[0]-(mn-i-1)/a[0];	
		else
			ans+=(mx-i)/a[0]-(d[i]-i-1)/a[0];	
	}
	printf("%lld\n",ans);
	return 0;
}
