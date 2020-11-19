#include<iostream>
using namespace std;
typedef long long ll;
ll f[120]={1},p=1000000007;
int t,n;
int main()
{
	for(int i=1;i<100;i++)
		f[i+1]=(f[i]+f[i-1])*i%p;
	for(cin>>t;t--;cout<<f[n]<<endl)
		cin>>n;
	return 0;
}
