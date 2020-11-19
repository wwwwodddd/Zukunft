#include<stdio.h>
int f[50000];
int i,j,n,ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=2;i<n;i++)
	{
		if(f[i]==i)
			for(j=i;j<n;j+=i)
				f[j]=f[j]/i*(i-1);
		ans+=f[i];
	}
	printf("%d",ans*2+3);
	return 0;
}