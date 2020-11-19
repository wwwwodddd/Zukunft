#include<stdio.h>
#include<algorithm>
using namespace std;
int n,x,y,t;
int a[1000020];
int p[1000020];
bool cmp(int x,int y)
{
	return a[x]<a[y]||a[x]==a[y]&&x<y;
}
int main()
{
	while(scanf("%d %d %d",&n,&x,&y),n+x+y)
	{
		for(int i=0;i<n;i++)
			scanf("%d",a+i),p[i]=i;
		nth_element(p,p+x-1,p+n,cmp);
		nth_element(p+x,p+n-y,p+n,cmp);
		sort(p,p+x);
		sort(p+n-y,p+n);
		printf("Case %d\n",++t);
		for(int i=0;i<x;i++)
			printf("%d%c",p[i]+1,i==x-1?'\n':' ');
		reverse(p+n-y,p+n);
		for(int i=n-y;i<n;i++)
			printf("%d%c",p[i]+1,i==n-1?'\n':' ');
	}
	return 0;
}
