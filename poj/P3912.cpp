#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x[120],y[120],a[120][2],d[120];
int g[120][120];
int v[120];
int w,s,n,i,j,k,min,m;
int cmp(const void *x,const void *y)
{
	return *(int*)x-*(int*)y;
}
void calc(int x,int y)
{
	int p,i,j,k,re;
	p=a[x][0];
	re=0;
	for(i=x+1;i<=y-1;i++)
		if(a[i][1]>n&&(a[i][0]-p)%s==0)
		{
			k=-1;
			for(j=i-1;j>=x;j--)
			{
				if(i-j<s&&(a[j][1]<=n||a[j][0]!=a[i][0]-i+j))
				{
					k=a[i][0]-i+j;
					break;
				}
				if(i-j>=s)
					break;
			}
			if(k==-1)
				return;
			re+=(k-p)/s+1;
			p=k;
		}
	re+=(a[y][0]-p-1)/s+1;
	g[x][y]=re;
}
int main()
{
	while(1)
	{
		memset(a,0,sizeof(a));
		memset(g,0x3f,sizeof(g));
		memset(d,0x3f,sizeof(d));
		scanf("%d",&w);
		if(w==0)
			break;
		scanf("%d %d",&s,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
			a[i*2-1][0]=x[i];
			a[i*2][0]=y[i];
			a[i*2-1][1]=n+i;
			a[i*2][1]=i;
		}
		qsort(a+1,2*n,8,cmp);
		m=2*n+1;
		a[0][0]=0;
		a[m][0]=w;
		for(i=0;i<m;i++)
			if(a[i][1]<=n)
				for(j=i+1;j<=m;j++)
					calc(i,j);
			else
				for(j=1;j<m;j++)
					if(a[j][1]==a[i][1]-n)
						g[i][j]=0;
		d[0]=0;
		memset(v,0,sizeof(v));
		for(i=0;i<=m;i++)
		{
			min=0x7fffffff;
			for(j=0;j<=m;j++)
				if(!v[j]&&d[j]<min)
					min=d[k=j];
			v[k]=1;
			for(j=0;j<=m;j++)
				if(d[j]>d[k]+g[k][j])
					d[j]=d[k]+g[k][j];
		}
		printf("%d\n",d[m]);
	}
	return 0;
}
