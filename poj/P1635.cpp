#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
string k(string str)
{
	int i,s=0,d=0;
	vector<string>box;
	string c,r;
	for(i=0;i<str.length();i++)
	{
		d+=str[i]=='0'?1:-1;
		if(d==0)
		{
			c="0"+k(str.substr(s+1,i-s))+"1";
			box.push_back(c);
			s=i+1;
		}
	}
	sort(box.begin(),box.end());
	for(i=0;i<box.size();i++)
		r+=box[i];
	return r;
}
int main()
{
	int t;
	scanf("%d",&t);
	string s1,s2;
	while(t--)
	{
		cin>>s1>>s2;
		s1=k(s1);
		s2=k(s2);
		if(s1==s2)
			printf("same\n");
		else
			printf("different\n");
	}
	return 0;
}
