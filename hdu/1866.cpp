#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;
string s;
int v[1020][1020];
int xa,xb,ya,yb,z;
int main()
{
	while(getline(cin,s))
	{
		for(int i=0;i<1000;i++)
			for(int j=0;j<1000;j++)
				v[i][j]=0;
		z=0;
		for(int i=0;i<s.size();i++)
			if(!isdigit(s[i]))
				s[i]=' ';
		istringstream in(s);
		while(in>>xa)
		{
			in>>ya>>xb>>yb;
			if(xa>xb)
				swap(xa,xb);
			if(ya>yb)
				swap(ya,yb);
			for(int i=xa;i<xb;i++)
				for(int j=ya;j<yb;j++)
					v[i][j]=1;
		}
		for(int i=0;i<1000;i++)
			for(int j=0;j<1000;j++)
				z+=v[i][j];
		printf("%d\n",z);
	}
	return 0;
}
