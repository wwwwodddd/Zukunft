#include<iostream>
using namespace std;
typedef long long ll;
ll n;
int main()
{
	cin>>n;
	n=2*n+1;
	ll i;
	ll z=0;
	for(i=1;i*i<n;i++)
		if(n%i==0)
			z+=i+n/i;
	if(i*i==n)
		z+=i;
	cout<<z<<endl;
}