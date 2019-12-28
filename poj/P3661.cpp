#include<iostream>
using namespace std;
int d[10010];
int f[10010][510];
int n,m,i,j,k;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>d[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			f[i][j]=f[i-1][j-1]+d[i];
		f[i][0]=f[i-1][0];
		for(j=1;j<=m&&j<=i-j;j++)
			f[i][0]=max(f[i][0],f[i-j][j]);
	}
	cout<<f[n][0]<<endl;
	return 0;
}
