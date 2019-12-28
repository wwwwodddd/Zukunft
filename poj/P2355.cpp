#include<iostream>
using namespace std;
int dp[10005];
int a[10005];
int l[4];
int c[4];
int s,e,n,i,j,k;
int solve(int x,int y)
{
	int z=a[x]-l[y],l=s,r=x-1;
	if(z>a[x-1])
		return -1;
	while(l!=r)
	{
		if(a[(l+r)/2]<z)
			l=(l+r)/2+1;
		else
			r=(l+r)/2;
	}
	return l;
}
int main()
{
	cin>>l[1]>>l[2]>>l[3]>>c[1]>>c[2]>>c[3];
	cin>>n;
	cin>>s>>e;
	if(s>e)
		swap(s,e);
	for(i=2;i<=n;i++)
		cin>>a[i];
	for(i=s+1;i<=e;i++)
	{
		dp[i]=2000000000;
		for(int j=1;j<=3;j++)
			if((k=solve(i,j))>0)
				if(dp[i]>dp[k]+c[j])
					dp[i]=dp[k]+c[j];
	}
	cout<<dp[e]<<endl;
}
