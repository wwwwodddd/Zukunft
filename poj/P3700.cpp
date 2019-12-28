#include<iostream>
using namespace std;
int n,ans,a[60];
int u[60],d[60];
void dfs(int x,int y,int z) 
{
	if(x+y>=ans)return;
	if(z>n)
	{
		if(x+y<ans)ans=x+y;
		return;
	}
	int i,p;
	for(i=1;i<=x;i++)
		if(u[i]<a[z])
			break;
	p=u[i];
	u[i]=a[z];
	dfs(max(i,x),y,z+1);
	u[i]=p;
	for(i=1;i<=y;i++)
		if(d[i]>a[z])
			break;
	p=d[i];
	d[i]=a[z];
	dfs(x,max(i,y),z+1);
	d[i]=p;
}
int main()
{
	int i;
	while(scanf("%d",&n) && n)
	{
		ans=100;
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		dfs(0,0,1);
		printf("%d\n",ans);
	}
}
