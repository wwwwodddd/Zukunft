#include<iostream>
using namespace std;
int f[105][50000]={1};
int v,i,j,k,n,s;
int main()
{
	scanf("%d",&n);
	for(k=1;k<=n;k++)
	{
		scanf("%d",&v);
		s+=v;
		for(i=k;i>0;i--)
			for(j=v;j<=s;j++)
				f[i][j]|=f[i-1][j-v];
	}
	for(i=s/2;i>=0;i--)
		if(f[n/2][i]||f[(n+1)/2][i])
			break;
	printf("%d %d\n",min(i,s-i),max(i,s-i));
	return 0;
}
