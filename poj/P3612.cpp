#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
int f[105],a[100020],l[105],r[105],g[105];
int n,m,i,j,ans,z,k,c;
int main()
{
	scanf("%d%d",&n,&c);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		z=max(z,a[i]);
	}
	memset(f,0x3f,sizeof(f));
	for(i=a[0];i<=z;i++)
		f[i]=(i-a[0])*(i-a[0]);
	for(i=1;i<n;i++)
	{
		memcpy(g,f,sizeof(f));
		for(j=0;j<=z;j++)
			f[j]=l[j]=r[j]=inf;
		l[0]=g[0];
		for(j=1;j<=z;j++)
			l[j]=min(l[j-1],g[j]-c*j);
		r[z]=g[z]+z*c;
		for(j=z-1;j>=0;j--)
			r[j]=min(r[j+1],g[j]+c*j);
		for(j=a[i];j<=z;j++)
			f[j]=min(r[j]-c*j,l[j]+c*j)+(j-a[i])*(j-a[i]);
	}
	ans=inf;
	for(i=a[n-1];i<=z; i++)
		ans=min(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}