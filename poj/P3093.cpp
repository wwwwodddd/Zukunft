#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int i,j,k,n,m,csc,sum,ans,a[1001],f[1001];
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d%d",&n,&m);
		ans=sum=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		if(a[1]>m)
		{
			printf("%d %d\n",++k,0);
			continue;
		}
		f[0]=1;
		for(i=n;i>0;i--)
		{
			sum-=a[i];
			for(j=max(m-sum-a[i]+1,0);j<=m-sum;j++)
				ans+=f[j];
			for(j=m;j>=a[i];j--)
				f[j]+=f[j-a[i]];
		}
		printf("%d %d\n",++k,ans);
	}
	return 0;
}