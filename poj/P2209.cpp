#include<iostream>
using namespace std;
int n,e;
double ans,x;
int main()
{
	cin>>n>>e;
	while(n--)
	{
		cin>>x;
		ans+=max(pow(x,e),0.0);
	}
	cout<<ans;
	return 0;
}