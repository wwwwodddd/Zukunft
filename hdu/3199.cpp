#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
long long f[10020];
long long p1,p2,p3,n,c1,c2,c3;
int main()
{
	for(;cin>>p1>>p2>>p3>>n;)
	{
		c1=c2=c3=0;
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
			f[i]=min(f[c1]*p1,min(f[c2]*p2,f[c3]*p3));
			if(f[i]==f[c1]*p1)
				c1++;
			if(f[i]==f[c2]*p2)
				c2++;
			if(f[i]==f[c3]*p3)
				c3++;
		}
		cout<<f[n]<<endl;
	}
}
