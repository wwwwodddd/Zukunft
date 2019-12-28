#include<stdio.h>
#include<string.h>
int m[60][60];
int d[60];
int n,l;
void prim()
{
	int i,j,l,x,ans=0;
	for(i=2;i<=n;i++)
		d[i]=m[1][i];
	for(i=1;i<n;i++)
	{
		l=0x3fffffff;
		for(j=2;j<=n;j++)
			if(d[j]>0&&d[j]<l)
				l=d[x=j];
		ans+=l;
		d[x]=0;
		for(j=2;j<=n;j++)
			if(d[j]>0&&d[j]>m[x][j])
				d[j]=m[x][j];
	}
	printf("%d\n",ans);
}
int main()
{
	int i,j,k,x,y,v;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&l);
		memset(m,0x7f,sizeof(m));
		for(i=0;i<l;i++)
		{
			scanf("%d %d %d",&x,&y,&v);
			if(v<m[x][y])
				m[x][y]=m[y][x]=v;
		}
		prim();
	}
	return 0;
}
