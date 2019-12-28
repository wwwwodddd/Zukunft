#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;
string F(string s)
{
	int v=0,l=0;
	vector<string>a;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
			v++;
		else
			v--;
		if(!v)
			a.push_back("0"+F(s.substr(l+1,i-l))+"1"),l=i+1;
	}
	sort(a.begin(),a.end());
	return accumulate(a.begin(),a.end(),string(""));
}
int main()
{
	int n;
	for(cin>>n;n--;)
	{
		string s,t;
		cin>>s>>t;
		puts(F(s)==F(t)?"same":"different");
	}
}
