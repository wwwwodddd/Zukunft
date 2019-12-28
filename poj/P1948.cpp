#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int x[41],n,p,h;
char dp[801][801];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		p+=x[i];
	}
	dp[0][0]=1,h=(p-1)>>1;
	for(int i=1;i<=n;i++)
		for(int j=h;j>=0;j--)
			for(int k=j;k>=0;k--)
				if (j>=x[i]&&dp[j-x[i]][k]||k>=x[i]&&dp[j][k-x[i]])
					dp[j][k]=1;
	double q=p/2.0,t,ans=-1;
	for(int i=h;i>=1;i--)
		for(int j=i;j+i>h;j--)
			if(dp[i][j])
			{
				t=(q-i)*(q-j)*(q-p+i+j);
				if(t>ans)
					ans=t;
			}
	if(ans<0)
		cout << -1 << endl;
	else
		cout << (int)(sqrt((double)q*ans)*100) << endl;
	return 0;
}

