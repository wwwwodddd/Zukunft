#include<iostream>
using namespace std;
int a[51000],b[51000];
int main()
{
	int i,j,n,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(j=1;j<=m;j++)
		scanf("%d",&b[j]);
	for(i=j=1;i<=n&&j<=m;)
	{
		if(a[i]+b[j]==10000)
			break;
		if(a[i]+b[j]<10000)
			i++;
		if(a[i]+b[j]>10000)
			j++;
	}
	if(i<=n&&j<=m)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
