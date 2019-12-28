#include<iostream>
#include<string>
#include<map>
using namespace std;
char s[35],s1[12],s2[12];
map<string,string>m;
int main()
{
	while(gets(s))
	{
		if(strlen(s)==0)
			break;
		sscanf(s,"%s %s",s1,s2);
		m[string(s2)]=string(s1);
	}
	while(gets(s))
		if(m.count(string(s)))
			cout<<m[string(s)]<<endl;
		else
			cout<<"eh\n";
	return 0;
}
