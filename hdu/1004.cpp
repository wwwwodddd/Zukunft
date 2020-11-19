/*
  Name: 
  Copyright: 
  Author: 
  Date: 29-12-11 22:26
  Description: 
*/
// xue xi le map de yongfa
//1A
#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int>mp;
map<string,int>::iterator it;
string s;
int csc,n,i;
int main()
{
	while(scanf("%d",&n),n)
	{
		mp.clear();
		while(n--)
		{
			cin >> s;
			mp[s]++;
		}
		it=mp.begin();
		s=it->first;
		for(it++;it!=mp.end();it++)
			if(it->second>mp[s])
				s=it->first;
		cout << s << endl;
	}
	return 0;	
}
