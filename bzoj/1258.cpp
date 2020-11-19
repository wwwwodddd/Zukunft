#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
string s,z[5];
int v[300],zc;
int main()
{
	cin>>s;
	if(*s.rbegin()=='4')
	{
		for(char c='1';c<'4';c++)
			*s.rbegin()=c,cout<<s<<endl;
		return 0;
	}
	for(int i=s.size()-1;i>0;i--)
		if(!v[s[i]])
		{
			v[s[i]]=1;
			z[zc++]=s.substr(0,i)+"4";
		}
	sort(z,z+zc);
	for(int i=0;i<zc;i++)
		cout<<z[i]<<endl;
	return 0;
}
