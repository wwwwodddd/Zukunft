#include<iostream>
using namespace std;
long long a[4000000],a1,b1,c1,a2,b2,c2,u1,u2;
int n,i,p1,p2;
int main()
{
	cin>>a[0]>>n>>a1>>b1>>c1>>a2>>b2>>c2;
	for(int i=1;i<n;i++)
	{
		u1=a1*a[p1]/c1+b1;
		u2=a2*a[p2]/c2+b2;
		if(u1<u2)
			a[i]=u1,p1++;
		else if(u1>u2)
			a[i]=u2,p2++;
		else if(u1==u2)
			a[i]=u1,p1++,p2++;
	}
	cout<<a[n-1];
	return 0;
}
