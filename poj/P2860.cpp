#include<stdio.h>
int n,m,k,i,ans,a[30];
int ax(int x)
{
	return x>0?x:0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<2*k;i++)
		scanf("%d",&a[i]);
	for(i=0;i<k;i++)
		ans+=ax(a[i+k]-a[i]);
	printf("%d\n",ans);
	return 0;
}
