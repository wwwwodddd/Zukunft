#include <iostream>
using namespace std;
char c[]=" abcdefghijklmnopqrstuvwxyz+*/?";
int q[140];
int p[32],r[32];
int s[32][32],f[32][32];
char u[32];
int n,T,i,j,k,l;
int sum,cnt,now;
int main()
{
	for(i=1;i<=30;i++)
		q[c[i]]=i;
	scanf("%d",&T);
	while(T--)
	{
		sum=0;
		cnt=0;
		now=30;
		scanf("%d",&n);
		memset(f,0x3f,sizeof(f));
		memset(p,0,sizeof(p));
		for(i=0;i<n;i++)
		{
			scanf("%s",u);
			for(j=0;u[j];j++)
				p[q[u[j]]]++;
		}
		for(i=1;i<=19;i++)
		{
			sum+=p[i]*i;
			f[1][i]=sum;
			s[1][i]=1;
		}
		for(i=2;i<=12;i++)
			for(j=i;j<=30;j++)
				for(k=i;k<=j;k++)
				{
					sum=0;
					for(l=k;l<=j;l++)
						sum+=p[l]*(l-k+1);
					if(f[i][j]>f[i-1][k-1]+sum)
					{
						f[i][j]=f[i-1][k-1]+sum;
						s[i][j]=k;
					}
				}
		for(i=12;i>1;i--)
		{
			r[cnt++]=s[i][now];
			now=s[i][now]-1;
		}
		for(i=cnt-1;i>=0;i--)
			printf("%c",c[r[i]]);
		printf("\n");
	}
	return 0;
}
