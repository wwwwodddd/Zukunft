#include<stdio.h>
#include<string.h>
int a[30][10];
int c[30],d[30];
int p[10];
int n,m,mn;
int i,j,k;
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		memset(p,0,sizeof(p));
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		}
		for(i=0;i<n;i++)
		{
			p[a[i][0]]+=c[i];
			d[i]=0;
		}
		for(i=0;i<m;i++)
		{
			mn=0xffff;
			for(j=1;j<=m;j++)
				if(p[j]<=mn)
					mn=p[k=j];
			p[k]=0xffff;
			for(j=0;j<n;j++)
				if(a[j][d[j]]==k)
				{
					while(p[a[j][d[j]]]==0xffff)
						d[j]++;
					p[a[j][d[j]]]+=c[j];
				}
		}
		printf("%d\n",k);
	}
	return 0;
}