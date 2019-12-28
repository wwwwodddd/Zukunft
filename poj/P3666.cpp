#include<iostream>
using namespace std;
long long dp[2010][2010];
long long k;
int b[2010];
int a[2010];
int i,j,n;
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int Z(int x)
{
	return x>-x?x:-x;
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		b[i]=a[i];
	qsort(b+1,n,sizeof(int),cmp);
	for(j=1;j<=n;j++)
		dp[1][j]=Z(a[1]-b[j]);
	for(i=2;i<=n;i++)
	{
		k=dp[i-1][1];
		for(j=1;j<=n;j++)
		{
			k=min(dp[i-1][j],k);
			dp[i][j]=k+Z(a[i]-b[j]);
		}
	}
	k=dp[n][n];
	for(i=n;i>0;i--)
		k=min(k,dp[n][i]);
	cout<<k<<endl;
	return 0;
}
