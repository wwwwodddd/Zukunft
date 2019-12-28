#include<iostream>
using namespace std;
int v[105][105];
char c[20];
int main ()
{
	int x,n,i,j,k;
	while(scanf("%d",&n)!=EOF)
	{
		memset(v,0x3f,sizeof(v));
		for(i=1;i<=n;i++)
			v[i][i]=0;
		for(i=1;i<=n;i++)
			for(j=1;j<i;j++)
			{
				cin>>c;
				if(c[0]!='x')
				{
					sscanf(c,"%d",&x);
					v[i][j]=v[j][i]=x;
				}
			}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(v[i][k]+v[k][j]<v[i][j])
						v[i][j]=v[i][k]+v[k][j];
		int a=0;
		for(i=1;i<=n;i++)
			a=max(a,v[i][1]);
		printf("%d\n",a);
	}
	return 0;
}
