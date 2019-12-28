#include<iostream>
using namespace std;
char c1[110],c2[110];
int dp[110][110];
void print(int s,int t)
{
	int i,j,k;
	if(s==0&&t==0)
		return;
	if(s==0)
	{
		print(s,t-1);
		cout<<c2[t-1];
		return;
	}
	else if(t==0)
	{
		print(s-1,t);
		cout<<c1[s-1];
		return;
	}
	else if(c1[s-1]==c2[t-1])
	{
		print(s-1,t-1);
		cout<<c1[s-1];
	}
	else if(dp[s-1][t]+1==dp[s][t])
	{
		print(s-1,t);
		cout<<c1[s-1];
	}
	else 
	{
		print(s,t-1);
		cout<<c2[t-1];
	}
}
int main()
{
	int i,j,k;
	while(cin>>c1>>c2)
	{
		for(i=1;i<=strlen(c1);i++)
			dp[i][0]=i;
		for(i=1;i<=strlen(c2);i++)
			dp[0][i]=i;
		for(i=1;i<=strlen(c1);i++)
			for(j=1;j<=strlen(c2);j++)
				if(c1[i-1]==c2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
		print(strlen(c1),strlen(c2));
		cout<<endl;
	}
	return 0;
}
