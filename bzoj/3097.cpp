#include<iostream>
#include<string>
using namespace std;
string inv(string s)
{
	string re;
	for(int i=0;i<s.size();i++)
		re+=s[i]=='a'?'b':'a';
	return re;
}
int main()
{
	string s="a";
	for(int i=0;i<13;i++)
		s+=inv(s);
	s+=s;
	s[0]='b';
	cout << s.size() << ' ' << s.size()/4 << endl;
	cout << s << endl;
	return 0;
}
