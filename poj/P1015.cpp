#include <iostream>
using namespace std;
long i,j,k,n,m,t,z,q;
long p[210],d[210],f[210],s[210];
long c[30];
long r[30][1000];
char w[30][1000][200];
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	while(scanf("%d %d",&n,&m)&&n+m)
	{
		for(i=0;i<n;i++)
		{
			cin>>p[i]>>d[i];
			f[i]=p[i]-d[i];
			s[i]=p[i]+d[i];
		}
		z=20*m;
		memset(r,-1,sizeof(r));
		r[0][z]=0;
		for(k=0;k<n;k++)
			if(f[k]<0)
			{
				for(i=m-1;i>=0;i--)
					for(j=-f[k];j<=z*2;j++)
						if(r[i][j]!=-1&&r[i+1][j+f[k]]<r[i][j]+s[k])
							r[i+1][j+f[k]]=r[i][j]+s[k],memcpy(w[i+1][j+f[k]],w[i][j],sizeof(w[i][j])),w[i+1][j+f[k]][k]=1;
			}
			else
			{
				for(i=m-1;i>=0;i--)
					for(j=0;j<=z*2-f[k];j++)
						if(r[i][j]!=-1&&r[i+1][j+f[k]]<r[i][j]+s[k])
							r[i+1][j+f[k]]=r[i][j]+s[k],memcpy(w[i+1][j+f[k]],w[i][j],sizeof(w[i][j])),w[i+1][j+f[k]][k]=1;
			}
		for(i=0;i<=z;i++)
			if(r[m][z+i]>r[m][z-i])
			{
				t=z+i;
				break;
			}
			else if(r[m][z-i]!=-1)
			{
				t=z-i;
				break;
			}
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",++q,(r[m][t]+t-z)/2,(r[m][t]-t+z)/2);
		for(i=0;i<n;i++)
			if(w[m][t][i])
				printf(" %d",i+1);
		printf("\n\n");
	}
	return 0;
}