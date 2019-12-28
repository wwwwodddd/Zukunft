#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
string s,c;
int main()
{
	int p;
	while(cin >> s)
	{
		while((cin >> c)&&c!="END")
		{
			p=s.find(c,0); 
			if(c=="NULL"||p==0)
				cout << "0 NULL" << endl;
			else if(p==-1)
				cout << s.size() << ' ' << s << endl;
			else
				cout << p << ' ' << s.substr(0,p) << endl;
		}
	}
	return 0;
}