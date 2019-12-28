#include<iostream>
#include<string>
using namespace std;
string s,s1,s2,s3;
int trans(string s)
{
	int re=0;
	for(int i=s.length()-1;i>=0;i--) 
		re=re*10+s[i]-'0';
	return re;
}
int main()
{
	while(cin>>s)
	{
		int p1=s.find("+");
		int p2=s.find("=");
		s1=s.substr(0,p1);
		s2=s.substr(p1+1,p2-p1-1);
		s3=s.substr(p2+1,s.length()-1-p2);
		cout<<((trans(s1)+trans(s2)==trans(s3))?"True":"False")<<endl;
		if (s=="0+0=0")
			break;
	}
	return 0;
}
