#include<stdio.h>
int s[120],c[120],a[120][120];
int n,m,x,z,t;
int main()
{
	for(;~scanf("%d %d",&n,&m);)
	{
		for(int i=0;i<n;i++)
			s[i]=0;
		for(int j=0;j<m;j++)
			c[j]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",a[i]+j),s[i]+=a[i][j],c[j]+=a[i][j];
		for(int i=0;i<n;i++)
			printf("%.2f%c",(double)s[i]/m,i<n-1?' ':'\n');
		for(int j=0;j<m;j++)
			printf("%.2f%c",(double)c[j]/n,j<m-1?' ':'\n');
		for(int i=z=0,j;i<n;i++)
		{
			for(j=0;j<m;j++)
				if(n*a[i][j]<c[j])
					break;
			if(j==m)
				z++;
		}
		printf("%d\n\n",z);
	}
}
