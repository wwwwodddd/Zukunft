#include<stdio.h>
int n,r,u,x,y,z;
int c[1020],f[1020],t[1020];
double w[1020],mx;
int main()
{
	for(;scanf("%d %d",&n,&r),n+r;)
	{
		z=0;
		for(int i=1;i<=n;i++)
			scanf("%d",c+i),z+=w[i]=c[i],t[i]=1;
		for(int i=1;i<n;i++)
			scanf("%d %d",&x,&y),f[y]=x;
		for(int i=1;i<n;i++)
		{
			mx=0;
			for(int j=1;j<=n;j++)
				if(j!=r&&w[j]>mx)
					mx=w[u=j];
			w[u]=0;
			z+=c[u]*t[f[u]];
			t[f[u]]+=t[u];
			c[f[u]]+=c[u];
			w[f[u]]=(double)c[f[u]]/t[f[u]];
			for(int j=1;j<=n;j++)
				if(f[j]==u)
					f[j]=f[u];
		}
		printf("%d\n",z);
	}
	return 0;
}
