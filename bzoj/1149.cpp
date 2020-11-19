#include<stdio.h>
#include<iostream>
using namespace std;
int n,u[100020],d[100020],l[100020],r[100020];
int ans;
inline void inc(int &x)
{
	if(x<0)
		x=0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",l+i,r+i),inc(l[i]),inc(r[i]);
	for(int i=n;i>0;i--)
	{
		u[i]=max(u[l[i]],u[r[i]])+1;
		d[i]=min(d[l[i]],d[r[i]])+1;
		if(u[l[i]]+d[l[i]]<u[r[i]]+d[r[i]])
			ans++;
		if(u[l[i]]!=d[l[i]]&&u[r[i]]!=d[r[i]])
			return puts("-1"),0;
	}
	if(u[1]>d[1]+1)
		puts("-1");
	else
		printf("%d",ans);
	return 0;
}
