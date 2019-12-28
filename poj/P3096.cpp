#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
string s;
int main()
{
while(cin >> s && s!="*")
	{
	for(int i=0;i<s.size();i++)
		{
		for(int j=1;i+j<s.size();j++)
			for(int k=i+1;k+j<s.size();k++)
				if(s[i]==s[k]&&s[i+j]==s[k+j])
					goto end;

		}
	cout << s << " is surprising." << endl;
	continue;
	end:
	cout << s << " is NOT surprising." << endl;
	}
return 0;
}