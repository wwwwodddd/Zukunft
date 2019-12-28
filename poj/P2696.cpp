#include<iostream>
using namespace std;
int n,a,b,c,d,e,f,g,h,i;
int z[1020],v[1020];
int Z(int x)
{
	if(v[x])
		return z[x];
	v[x]=1;
	if(x<3)
		return z[x];
	if(x%2)
		return z[x]=((d*Z(x-1)+e*Z(x-2)-f*Z(x-3))%g+g)%g;
	else
		return z[x]=((f*Z(x-1)-d*Z(x-2)+e*Z(x-3))%h+h)%h;
}
int main()
{
	cin>>n;
	while(n--)
	{
		memset(v,0,sizeof(v));
		cin>>z[0]>>z[1]>>z[2]>>d>>e>>f>>g>>h>>i;
		cout<<Z(i)<<endl;
	}
	return 0;
}