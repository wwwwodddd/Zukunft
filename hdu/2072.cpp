#include<iostream>
#include<sstream>
#include<set>
using namespace std;
string s;
set<string>v;
int main()
{
	while(getline(cin,s),s!="#")
	{
		v.clear();
		istringstream in(s);
		while(in>>s)
			v.insert(s);
		cout<<v.size()<<endl;
	}
	return 0;
}
