#include<iostream>
#include<stdio.h>
using namespace std;
int f[52][52],d[52][52];
int ver[52],b[52],g[52];
char edge[52],a[52];
int n,i,j,k,l,m,u,v,x,y,ans;
void scan()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s %d",&a[i],&b[i]);
	j=b[n];
	for(i=n;i>1;i--)
		b[i]=b[i-1];
	b[1]=j;
}
int cal(int s,int t,char p)
{
	return p=='t'?(s+t):s*t;
}
int main()
{
	scan();
	for(m=1;m<=n;m++)
	{
		j=m;
		for(i=1;i<=n;i++)
		{
			++j==n+1?j=1:0;
			ver[i]=b[j];
			edge[i]=a[j];
		}
		memset(f,0x80,sizeof(f));
		memset(d,0x7f,sizeof(d));
		for(i=1;i<=n;i++)
		{
			f[i][i]=ver[i];
			d[i][i]=ver[i];
		}
	for(l=1;l<n;l++)
		for(i=1;i<=n-l;i++)
		{
			j=i+l;
			for(k=i;k<j;k++)
			{
				u=cal(f[i][k],f[k+1][j],edge[k]);
				v=cal(f[i][k],d[k+1][j],edge[k]);
				x=cal(d[i][k],f[k+1][j],edge[k]);
				y=cal(d[i][k],d[k+1][j],edge[k]);
				f[i][j]=max(f[i][j],max(max(u,v),max(x,y)));
				d[i][j]=min(d[i][j],min(min(u,v),min(x,y)));
			}
		}
		g[m]=f[1][n];
		if(ans<g[m])
			ans=g[m];
		}
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		if(ans==g[i])
			printf("%d ",i);
	return 0;
}
