#include<iostream>
using namespace std;
int f[15][17][17],t,n;
void F()
{
	int i,j,k;
	f[0][8][8]=1;
	for(k=1;k<=14;k++)
		for(i=1;i<17;i++)
			for(j=1;j<17;j++)
				f[k][i][j]=f[k-1][i][j+1]+f[k-1][i][j-1]+f[k-1][i+1][j]+f[k-1][i+1][j+1]+f[k-1][i-1][j]+f[k-1][i-1][j-1];
}
int main()
{
	cin>>t;
	F();
	while(t--)
	{
		cin>>n;
		cout<<f[n][8][8]<<endl ;
	}
	return 0;
}
 
