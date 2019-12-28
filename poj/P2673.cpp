#include<iostream>
using namespace std;
int ans,t,x,m,d,s,y,z=1234567890;
int main()
{
	cin>>t>>x>>m;
	while(m--)
	{
		scanf("%d%d",&d,&s);
		if(s&&z>(d-1)/s)
			z=(d-1)/s;
	}
	if(z==0)
		ans=0;
	else if(t>=z)
		ans=z+(t-z)/2;
	else
		ans=t;
	cout<<x*ans<<endl;
	return 0;
}
