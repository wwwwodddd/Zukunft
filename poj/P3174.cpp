#include<iostream>
using namespace std;
int n,ans;
int x[800],y[800];
int i,j,k;
int main()
{
	int i;
	while(scanf("%d",&n)+1)
	{
		for(i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				for(k=j+1;k<=n;k++)
					if((x[i]-x[j])*(y[j]-y[k])==(x[j]-x[k])*(y[i]-y[j]))
						ans++;
		printf("%d\n",ans);
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				for(k=j+1;k<=n;k++)
					if((x[i]-x[j])*(y[j]-y[k])==(x[j]-x[k])*(y[i]-y[j]))
						printf("%d %d %d\n",i,j,k);
	}
	return 0;
}
