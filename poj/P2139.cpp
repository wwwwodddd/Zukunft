#include<iostream>
using namespace std;
int m,n,mn,h,l,sum;
int d[320][320],a[320];
int main()
{
	int i,j,k;
	memset(d,0x3f,sizeof(d));
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		d[i][i]=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&l);
		for(j=0;j<l;j++)
			scanf("%d",&a[j]);
		for(j=0;j<l;j++)
			for(k=0;k<j;k++)
				d[a[j]][a[k]]=d[a[k]][a[j]]=1;
	}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
	mn=0x3f3f3f3f;
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<=n;j++)
			sum+=d[i][j];
		mn=min(mn,sum);
	}
	printf("%d\n",mn*100/(n-1));
	return 0;
}
