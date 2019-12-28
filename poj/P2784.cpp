#include<stdio.h>
int n,m,q,sm,ans,t;
int a[1020][1020],b[1020][1020];
int x[1020],y[1020],w[1020],l[1020],d[1020],v[1020];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&q,&w[i]);
		for(int j=0;j<q;j++)
			scanf("%d",&t),l[t]|=1<<i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d %d",x+i,y+i);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			b[i][j]=b[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	ans=0x3f3f3f3f;
	for(int p=0;p<1<<m;p++)
	{
		int x,y;
		sm=0;
		for(int i=0;i<m;i++)
			if(p>>i&1)
				sm+=w[i];
		for(int i=1;i<=n;i++)
		{
			v[i]=0;
			d[i]=0x3f3f3f3f;
			for(int j=i;j<=n;j++)
				if(l[i]&l[j]&p)
					a[i][j]=a[j][i]=0;
				else
					a[i][j]=a[j][i]=b[i][j];
		}
		d[1]=0;
		for(int i=0;i<n;i++)
		{
			y=0x3f3f3f3f;
			for(int j=1;j<=n;j++)
				if(!v[j]&&d[j]<y)
					y=d[x=j];
			v[x]=1;
			sm+=y;
			for(int j=1;j<=n;j++)
				if(!v[j]&&d[j]>a[x][j])
					d[j]=a[x][j];
		}
		if(sm<ans)
			ans=sm;
	}
	printf("%d\n",ans);
	return 0;
}
