#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
string s,x;
int f;
int main()
{
while(cin >> s &&s!=".")
{
for(int i=1;i<=s.size();i++)
	if(s.size()%i==0)	
	{
	f=1;
	x=s.substr(0,i);
		for(int j=i;j<s.size();j+=i)
			if(x!=s.substr(j,i))
				{
				f=0;
				break;
				}
	if(f==1)
		{
		printf("%d\n",s.size()/i);
		break;	
		}
	}
}
return 0;
}