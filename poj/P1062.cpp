#include<iostream>
using namespace std;
int d[105],c[105],l[105],g[105][105];
int t[105];
int i,j,m,n,p,x,y,ans;
int D(int min,int max)
{
	int i,j,k,r;
	memcpy(d,c,sizeof(d));
	for(i=1;i<=n;i++)
		if(l[i]<min||l[i]>max)
			t[i]=0;
		else
			t[i]=1;
	for(i=0;i<n;i++)
	{
		r=0x3f3f3f3f;
		for(j=1;j<=n;j++)
			if(t[j]&&r>d[j])
			{
					r=d[j];
					k=j;
			}
		t[k]=0;
		if(k==1)
			return d[k];
		for(j=1;j<=n;j++)
			if(d[j]>d[k]+g[k][j])
				d[j]=d[k]+g[k][j];
	}
	return d[1];
}
int main()
{
	while(scanf("%d%d",&m,&n)+1)
	{
		ans=0x3f3f3f3f;
		memset(g,0x3f,sizeof(g));
		for(i=1;i<=n;i++)
		{
			scanf("%d %d %d",c+i,l+i,&x);
			while(x--)
			{
				scanf("%d %d",&j,&p);
				g[j][i]=p;
			}
		}
		for(i=l[1]-m;i<=l[1];i++)
		{
			y=D(i,i+m);
			if(ans>y)
				ans=y;
		}
		printf("%d\n",ans);
	}
	return 0;
}