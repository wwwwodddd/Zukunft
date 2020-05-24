#include<iostream>
using namespace std;
const int N=5e5+2;
int t,n,a[N],x[N],C;
int i;
void D()
{
	int k = i;
	while(i>1&&(x[i-1]==k||x[i-1]==-1))
		i--,D();
	a[k]=++C;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--&&cin>>n)
	{
		C=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		i = n + 1;
		D();
		if(i>1)
			cout<<-1<<'\n';
		else
		{
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
			cout<<'\n';
		}
	}
	return 0;
}
