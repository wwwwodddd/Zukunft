#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[10020];
int cal(string &a,string &b)
{
	int i;
	for(i=0;i<a.size()&&i<b.size()&&a[i]==b[i];i++)
		;
	return a.size()+b.size()-i-i;
}
int main()
{
	int i,n;
	for(;cin>>n;)
	{
		for(int i=0;i<n;i++)
			cin>>s[i];
		sort(s,s+n);
		s[n]="";
		int z=0,mx=0;
		for(int i=0;i<n;i++)
		{
			z+=cal(s[i],s[i+1])+1;
			mx=max(mx,(int)s[i].size());
		}
		cout<<z+s[0].size()-mx<<endl;
	}
}
