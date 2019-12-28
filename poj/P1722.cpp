#include<stdio.h>
#include<string.h>
const int d=10200;
int a[120];
int f[120][20400];
int p[120];
int i,j,k,m,n,t;
int main()
{
	scanf("%d %d",&n,&t);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	memset(f,0,sizeof(f));
	f[1][a[1]+d]=1;
	f[2][a[1]-a[2]+d]=-1;
	for(i=3;i<=n;i++)
		for(j=200;j<=20200;j++)
			if(f[i-1][j])
			{
				f[i][j+a[i]]=1;
				f[i][j-a[i]]=-1;
			}
	j=t+d;
	for(i=n;i>0;i--)
		if(f[i][j]==1)
		{
			p[i]=1;
			j-=a[i];
		}
		else if(f[i][j]==-1)
		{
			p[i]=0;
			j+=a[i];
		}
	m=0;
	for(i=3;i<=n;i++)
		if(p[i])
			printf("%d\n",i-1-(m++));
	for(i=2;i<=n;i++)
		if(!p[i])
			printf("1\n");
}