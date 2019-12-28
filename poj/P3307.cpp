#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL ans[100020],z;
int b,f;
LL a[4]={2,3,5,7};
int main()
{
	int t,n;
	z=1000000;
	z*=1000000;
	z*=1000000;
	b=f=0;
	ans[f++]=1;
	for(int k=0;k<4;k++)
		for(int i=0;i<f;i++)
			if(ans[i]*a[k]<=z)
				ans[f++]=ans[i]*a[k];
	sort(ans,ans+f);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%I64d\n",ans[n-1]);
	}
	return 0;
}