#include<stdio.h>
#include<iostream>
using namespace std;
long long n,m;
long long ans=0x3f3f3f3f3f3f3f3fLL;
int u,d;
int main()
{
	cin>>n>>m;
	while(m--)
	{
		scanf("%d %d",&u,&d);
		long long ud=n*u%(u+d);
		if(ud==0)
			ud+=u+d;
		ans=min(ans,ud);
	}
	cout << ans;
}
