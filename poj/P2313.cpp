#include<iostream>
#include<algorithm>
using namespace std;
int a[105],b[105];
int n,i,j,k,ans;
int S(int x,int y,int z)
{
	int c[3]={x,y,z};
	sort(c,c+3);
	return c[1];
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	b[1]=a[1];
	b[n]=a[n];
	for(i=2;i<n;i++)
		b[i]=S(b[i-1],a[i],a[i+1]);
	for(i=1;i<=n;i++)
		ans+=abs(a[i]-b[i]);
	for(i=1;i<n;i++)
		ans+=abs(b[i]-b[i+1]);
	cout<<ans<<endl;
	return 0;
}
