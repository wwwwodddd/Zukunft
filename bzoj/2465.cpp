#include<stdio.h>
#include<algorithm>
using namespace std;
int a[300],c[300],w[300],n,m,x,y,ans,sum;
int main()
{
	while(scanf("%d %d",&n,&m),n+m)
	{
		ans=sum=0;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		reverse(a,a+n);
		for(int i=0;i<m;i++)
			scanf("%d %d",c+i,w+i);
		for(int i=0;i<n;i++)
		{
			x=-1,y=0x7fffffff;
			for(int j=0;j<m;j++)
				if(c[j]&&a[i]<=w[j]&&w[j]<y)
					y=w[x=j];
			if(~x)
				c[x]--,ans++,sum+=a[i];
		}
		printf("%d %d\n",ans,sum);
	}
	return 0;
}
