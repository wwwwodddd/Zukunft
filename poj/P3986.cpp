#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,z,p=1000000003;
int a[60],b[60][40],v[40],f[60][40][2];
int main()
{
	for(;scanf("%d %d",&n,&z),n;)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",a+i),a[i]++;
		memset(b,0,sizeof b);
		for(int i=1;i<=n;i++)
			for(int j=0;j<31;j++)
				b[i][j]=b[i-1][j]^(a[i]>>j&1);
		v[31]=1;
		for(int i=30;~i;i--)
			v[i]=v[i+1]&&(b[n][i]==(z>>i&1));
		memset(f,0,sizeof f);
		f[0][0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<31;j++)
				for(int o=0;o<2;o++)
					if(f[i-1][j][o])
						for(int k=0;k<31;k++)
							if(a[i]>>k&1)
							{
								int s;
								if(k>j)
									s=b[i-1][k];
								else
									s=o^(k==j?0:a[i]>>j&1);
								f[i][max(j,k)][s]=(((long long)f[i-1][j][o]<<min(j,k))+f[i][max(j,k)][s])%p;
							}
		int ans=0;
		for(int i=30;~i;i--)
			if(v[i+1])
				ans=(ans+f[n][i][z>>i&1])%p;
		printf("%d\n",ans);
	}
	return 0;
}
