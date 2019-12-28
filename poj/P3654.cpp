#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
set<char>o[30];
string pt;
vector<pair<char,string> >vec;
char s[100];
int l,st,ed,op,t;
int main()
{
	while(gets(s),*s!='#')
	{
		l=strlen(s);
		s[l]=',';
		s[l+1]='\0';
		int i;
		printf("%d:",++t);
		fr(i,26)
			o[i].clear();
		for(st=0;st<=l;st=ed+1)
		{
			for(i=st;s[i]!=',';i++)
				;
			ed=i;
			for(i=st;i<ed;i++)
				if(s[i]=='+'||s[i]=='-'||s[i]=='=')
					break;
			op=i;
			if(s[i]=='+')
			{
				for(int j=st;j<op;j++)
					for(int k=op+1;k<ed;k++)
						o[s[j]-'A'].insert(s[k]);
			}
			else if(s[i]=='-')
			{
				for(int j=st;j<op;j++)
					for(int k=op+1;k<ed;k++)
						o[s[j]-'A'].erase(s[k]);
			}
			else if(s[i]=='=')
			{
				for(int j=st;j<op;j++)
				{
					o[s[j]-'A'].clear();
					for(int k=op+1;k<ed;k++)
						o[s[j]-'A'].insert(s[k]);
				}
			}
		}
		vec.clear();
		fr(i,26)
		{
			pt="";
			fe(j,o[i])
				pt+=*j;
			if(pt.size())
				vec.push_back(make_pair(i+'A',pt));
		}
		for(int i=0;i<vec.size();i++)
		{
			if(i!=vec.size()-1&&vec[i].second==vec[i+1].second)
				cout<<vec[i].first;
			else	
				cout<<vec[i].first<<vec[i].second;
		}
		puts("");
	}
}
