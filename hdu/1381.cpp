#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int>m;
int t,n,c;
string s;
int main()
{
	for(cin>>t;t--;m.clear())
	{
		cin>>n>>c>>s;
		for(int i=0;i<=s.size()-n;i++)
			m[string(s,i,n)]++;
		cout<<m.size()<<endl;
	}
	return 0;
}
