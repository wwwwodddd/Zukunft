#include<stdio.h>
#include<iostream>
using namespace std;
long long x=-1E12,y=1E12,n,m;
int main()
{
	for(cin>>n;n--;swap(x=2*m-x,y=2*m-min(m,y)))
		scanf("%lld",&m);
	cout<<max(y-x+1,0LL);
	return 0;
}