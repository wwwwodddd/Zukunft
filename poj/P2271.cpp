#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;
string s;
int l,w;
int main()
{
	while(cin>>s)
	{
		if(s=="<br>")
		{
			l=w=0;
			printf("\n");
		}
		else if(s=="<hr>")
		{
			if(l)
				puts("");
			puts("--------------------------------------------------------------------------------");
			l=w=0;
		}
		else if(l+s.size()+1>80)
		{
			cout<<endl<<s;
			l=s.size();
			w=1;
		}
		else
		{
			if(w)  
				printf(" ");
			cout<<s;
			w=1;
			l+=s.size()+1;
		}
	}
	return 0;
}
