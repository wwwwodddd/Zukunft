#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<string>v;
string s;
int n;
int main()
{
	for(;scanf("%d",&n),n;)
	{
		v.clear();
		for(int i=0;i<n;i++)
			cin>>s,v.push_back(s);
		int z;
		for(z=0;;z++)
		{
			for(int i=0;i<n;i++)
			{
				v[i].erase(0,1);
				if(!v[i].size())
					goto end;
			}
			for(int i=0;i<n;i++)
				if(find(v.begin()+i+1,v.end(),v[i])!=v.end())
					goto end;
		}
		end:;
		printf("%d\n",z);
	}
}
