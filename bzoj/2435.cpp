#include<stdio.h>
int h[1000020];
int a[2000020][3],tot;
int u[1000020];
int v[1000020];
int fa[1000020];
int q[2000020],b,f;
int n,i,j;
long long ans;
void add(int x,int y,int z)
{
	tot++;
	a[tot][0]=h[x];
	a[tot][1]=y;
	a[tot][2]=z;
	h[x]=tot;
}
void bfs()
{
	int p,i;
	b=f=0;
	q[f++]=1;
	v[1]=1;
	while(b<f)
	{
		p=q[b++];
		for(i=h[p];i;i=a[i][0])
			if(!v[a[i][1]])
			{
				v[a[i][1]]=1;
				fa[a[i][1]]=p;
				q[f++]=a[i][1];
			}
	}
}
long long ab(int x)
{
	return x>0?x:-x;
}
int main()
{
	int x,y,z;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	bfs();
	for(i=f-1;i>=0;i--)
	{
		u[q[i]]++;
		u[fa[q[i]]]+=u[q[i]];
	}
	for(i=1;i<=n;i++)
		for(j=h[i];j;j=a[j][0])
			if(u[i]>u[a[j][1]])
				ans+=ab(n-u[a[j][1]]-u[a[j][1]])*a[j][2];
	printf("%lld",ans);
	return 0;
}