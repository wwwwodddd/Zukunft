#include<iostream>
using namespace std;
long long s[10005],f[10005],su[10005],sd[10005],dd[10005],uu[10005];
int t,n,u,d,i;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&u,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%I64d",&f[i]);
			s[i]=s[i-1]+f[i];
		}
		uu[n]=dd[1]=su[n+1]=sd[0]=0;
		for(i=1;i<=n;i++)
			sd[i]=sd[i-1]+s[i];
		for(i=n;i>=1;i--)
			su[i]=su[i+1]+s[n]-s[i-1];
		for(i=2;i<=n;i++)
			dd[i]=s[i-2]*d+dd[i-1]+f[i-1]*d+sd[i-2];
		for(i=n-1;i>=1;i--)
			uu[i]=(s[n]-s[i+1])*u+uu[i+1]+f[i+1]*u+su[i+2];
		int z=1;
		for(i=2;i<=n;i++)
			if(dd[z]+uu[z]>=dd[i]+uu[i])
				z=i;
		printf("%d\n",z);
	}
	return 0;
}