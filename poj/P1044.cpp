#include<stdio.h>
int y[22],a[22],b[22],d[22];
int n,k,i,mx,u,ans;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		printf("Case #%d:\n",++k);
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&y[i],&a[i],&b[i]);
			d[i]=b[i]-a[i];
			if(a[i]>mx)
				mx=a[i];
			y[i]=y[i]%d[i];
		}
		u=d[0];
		ans=y[0];
		for(i=1;i<n;i++)
		{
			while(ans%d[i]!=y[i]&&ans<10002)
			ans+=u;
			if(ans>10002)
				break;
			u=u/gcd(u,d[i])*d[i];
		}
		while(ans<mx)
			ans+=u;
		if(ans>=10000)
			printf("Unknown bugs detected.\n\n");
		else
			printf("The actual year is %d.\n\n",ans);
	}
	return 0;
}
