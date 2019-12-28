#include<iostream>
using namespace std;
int t,n,m,a[520],s[520],f[520][520],p[520];
int i,j,k,z,u;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0x3f,sizeof(f));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			s[i]=s[i-1]+a[i];
		}
		f[0][0]=0;
		for(j=1;j<=m;j++)
			for(i=1;i<=n;i++)
				for(k=0;k<i;k++)
					f[j][i]=min(f[j][i],max(f[j-1][k],s[i]-s[k]));
		z=f[m][n];
		for(i=n,j=m-1,u=0;i>=1;i--)
		{
			u+=s[i]-s[i-1];
			if(u>z||i<=j)
			{
				p[j--]=i+1;
				u=s[i]-s[i-1];
			}
		}
		for(i=j=1;i<=n;i++)
		{
			if(j<m&&p[j]==i)
			{
				printf("/ ");
				j++;
			}
			printf("%d ",s[i]-s[i-1]);
		}
		printf("\n");
	}
	return 0;
}