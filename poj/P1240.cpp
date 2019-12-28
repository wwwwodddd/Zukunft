#include<iostream>
using namespace std;
int n,ans,p;
char a[33],b[33];
int C(int x)
{
	int i,re=1;
	for(i=1;i<=x;i++)
	{
		re*=n-i+1;
		re/=i;
	}
	return re;
}
void DFS(int x,int y)
{
	int i,q;
	q=0;
	for(i=x;i<=y;i++)
	{
		if(b[i]==a[p])
		{
			++q;
			++p;
			DFS(x,i-1);
			x=i+1;
		}
	}
	ans*=C(q);
}
int main()
{
	int m;
	while(cin>>n&&n)
	{
		cin>>a>>b;
		m=strlen(a);
		ans=1;
		p=1;
		DFS(0,m-2);
		cout<<ans<<endl;
	}
	return 0;
}
