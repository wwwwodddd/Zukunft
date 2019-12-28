#include<iostream>
using namespace std;
const int INF=0x3fffffff;
struct E{int y,u,w,z,n;}a[12];
int n,m,tot,ans,v[12],h[12];
void dfs(int u,int w)
{
	if(w>ans)
		return ;
	if(u==n)
	{
		ans=w;
		return;
	}
	for(int k=h[u];k;k=a[k].n)
		if(v[a[k].y]<=3)
		{
			v[a[k].y]++;
			if(v[a[k].u]>0)
				dfs(a[k].y,a[k].w+w);
			else
				dfs(a[k].y,a[k].z+w);
			v[a[k].y]--;
		}
}
int main()
{
	int x,y,u,w,z,i,j;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d%d%d%d%d",&x,&y,&u,&w,&z);
		tot++;
		a[tot].y=y;
		a[tot].u=u;
		a[tot].w=w;
		a[tot].z=z;
		a[tot].n=h[x];
		h[x]=tot;
	}
	v[1]=1;
	ans=INF;
	dfs(1,0);
	if(ans!=INF)
		cout<<ans<<endl;
	else
		cout<<"impossible"<<endl;
	return 0;
}