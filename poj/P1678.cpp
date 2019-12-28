#include<iostream>
#include<algorithm>
using namespace std;
int a[10010];
int f[10010];
int v[10010];
int i,t,n,x,y;
int F(int z)
{
	if(v[z])
		return f[z];
	v[z]=1;
	int re=0xcccccccc;
	for(int i=z+1;i<=n;i++)
		if(a[z]+x<=a[i]&&a[i]<=a[z]+y)
			re=max(re,a[i]-F(i));
		else if(a[i]>a[z]+y)
			break;
	if(re==0xcccccccc)
		return f[z]=0;
	return f[z]=re;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(v,0,sizeof(v));
		scanf("%d%d%d",&n,&x,&y);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		printf("%d\n",F(0));
	}
	return 0;
}