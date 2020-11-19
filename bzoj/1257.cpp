#include <iostream>
using namespace std;
typedef long long ll;
int a,l,r,n,k,cnt;
ll ans;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cnt++;
		a=k/i,l=i,r=a?k/a:n;
		if(r>=n)
			r=n;
		ans+=ll(k)*(r-l+1)-ll(a)*(l+r)*(r-l+1)/2;
	//	cout<<i<<' '<<a<<' '<<l<<' '<<r<<' '<<ll(k)*(r-l+1)-ll(a)*(l+r)*(r-l+1)/2<<endl;
		i=r;
	}
	cout<<ans<<endl;
}