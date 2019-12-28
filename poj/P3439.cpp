#include<stdio.h>
#include<string.h>
double l1,l2,l;
int t,n,x,y;
int d[1020];
double c[1020][2];
int g[1020][1020];
int v[1020];
double dis(int i,int j)
{
	return ((c[i][0]-c[j][0])*(c[i][0]-c[j][0])+(c[i][1]-c[j][1])*(c[i][1]-c[j][1]));
}
int Dijkstra(int x,int y)
{
	int i,j,k;
	int now;
	memset(v,0,sizeof(v));
	d[x]=0;
	v[x]=1;
	for(i=1;i<=n;i++)
		if(!v[i])
			d[i]=g[x][i];
	for(i=1;i<n;i++)
	{
		int min=0x3f3f3f3f;
		for(j=1;j<=n;j++)
			if(!v[j]&&d[j]<min)
			{
				min=d[j];
				now=j;
			}
		if(min==0x3f3f3f3f)
			return d[y];
		for(j=1;j<=n;j++)
			if(d[j]>d[now]+g[now][j])
				d[j]=d[now]+g[now][j];
		v[now]=1;
	}
	return d[y];
}
int main()
{
	int i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %lf %lf",&n,&x,&y,&l1,&l2);
		memset(g,0x3f,sizeof(g));
		l=(l1+l2)*(l1+l2);
		for(i=1;i<=n;i++)
			scanf("%lf %lf",&c[i][0],&c[i][1]);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				if(dis(i,j)<=l)
					g[i][j]=g[j][i]=1;
		int ans=Dijkstra(x,y);
		if(ans>0xffff)
			printf("Impossible\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
