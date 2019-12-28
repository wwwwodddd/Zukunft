#include<iostream>
#include<fstream>
using namespace std;
int dp[101];
char c[110];
char h[30]="22233344115566070778889990";
int r[101];
int n;
char a[50001][51];
char b[50001][51];
void print(int s)
{
	if(s==0)
		return;
	print(s-strlen(a[r[s]]));
	cout<<b[r[s]]<<' ';
}
int main()
{
	int i,j,k;
	while(cin>>c)
	{
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>b[i];
			for(j=0;j<strlen(b[i]);j++)
				a[i][j]=h[b[i][j]-'a'];
			a[i][strlen(b[i])]='\0';
		}
		for(i=1;i<=strlen(c);i++)
			dp[i]=strlen(c)+1;
		dp[0]=0;
		for(i=1;i<=strlen(c);i++)
			for(j=1;j<=n;j++)
				if(i>=strlen(a[j])&&strncmp(&c[i-strlen(a[j])],a[j],strlen(a[j]))==0)
					if(dp[i]>dp[i-strlen(a[j])]+1)
					{
						dp[i]=dp[i-strlen(a[j])]+1;
						r[i]=j;
					}
		if(dp[strlen(c)]==strlen(c)+1)
			cout<<"No solution.";
		else
			print(strlen(c));
		cout<<endl;
	}
	return 0;
}
