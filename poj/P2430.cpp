#include<iostream>
using namespace std;
int f[1005][1005][3];
int a[1005][2],c[1005],d[1005];
int n,m,p,tot,i,j,u,ds,k;
//b[i] a[i][0];
//a[i] a[i][1];
int cmp(const void *a,const void *b)
{
	return ((int*)a)[1]-((int*)b)[1];
}
int main()
{
	scanf("%d %d %d",&n,&m,&p);
	for(i=1;i<=n;i++)
		scanf("%d %d",&a[i][0],&a[i][1]);
	qsort(a+1,n,8,cmp);
	i=1;
	while(i<=n)
	{
		tot++;
		if(a[i][1]==a[i+1][1])
		{
			c[tot]=2;
			d[tot]=i;
			i+=2;
		}
		else
		{
			c[tot]=1;
			d[tot]=i;
			i++;
		}
	}
	memset(f,0x3f,sizeof(f));
	f[0][0][0]=f[0][0][1]=f[0][0][2]=0;
	for(i=1;i<=tot;i++)
		for(j=1;j<=m;j++)
			if(c[i]==1)
			{
				u=min(min(f[i-1][j-1][0],f[i-1][j-1][1]),f[i-1][j-1][2]);
				ds=a[d[i]][1]-a[d[i-1]][1];
				f[i][j][0]=min(u+1,f[i-1][j][2]+ds);
				if(a[d[i-1]][0]==a[d[i]][0])
					f[i][j][0]=min(f[i][j][0],f[i-1][j][0]+ds);
				f[i][j][1]=min(u+2,f[i-1][j][1]+2*ds);
				if(j>1)
					f[i][j][2]=min(f[i-1][j][2]+2*ds,f[i-1][j-1][0]+ds+1);
			}
			else
			{
				u=min(min(f[i-1][j-1][0],f[i-1][j-1][1]),f[i-1][j-1][2]);
				ds=a[d[i]][1]-a[d[i-1]][1];
				f[i][j][1]=min(u+2,f[i-1][j][1]+2*ds);
				if(j>1)
				{
					u=min(min(f[i-1][j-2][0],f[i-1][j-2][1]),f[i-1][j-2][2]);
					f[i][j][2]=min(min(u+2,f[i-1][j][2]+2*ds),f[i-1][j-1][0]+ds+1);
				}
			}
	printf("%d",min(min(f[tot][m][0],f[tot][m][1]),f[tot][m][2]));
	return 0;
}