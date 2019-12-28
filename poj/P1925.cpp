#include<math.h>
#include<iostream>
using namespace std;
int f[1000020];
int a[5020],b[5020];
int t,n,i,j,k,csc;
int main()
{
	scanf("%d",&csc);
	while(csc--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d %d",&a[i],&b[i]);
		memset(f,0x3f,sizeof(f));
		f[0]=0;
		for(i=2;i<=n;i++)
			for(j=max(0,a[i]-(int)sqrt((double)b[i]*b[i]-(double)(b[i]-b[1])*(b[i]-b[1])));j<=a[i];j++)
			{
				k=min(a[n],a[i]*2-j);
				f[k]=min(f[k],f[j]+1);
			}
		printf("%d\n",f[a[n]]==0x3f3f3f3f?-1:f[a[n]]);
	}
	return 0;
}