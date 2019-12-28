#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int d[1020],l[1020],n;
string s[1020];
int  chck(string a,string b)
{
if(a.length()!=b.length()+1)
	return 0;
int i,l=0;
for(i=0;i<b.length();i++)
	if(a[i]==b[l])
		l++;
if(l==b.length())
	return 1;
if(a[i]==b[l]&&l==b.length()-1)
	return 1;
else
	return 0;
}
int dfs(int x)
{
	int a=0,b=0;
	if(d[x])
		return d[x];
	for(int i=1;i<=n;i++)
		if(chck(s[i],s[x]))
			a<dfs(i)?a=dfs(i),l[x]=i:0;
	return d[x]=a+1;
}
int main()
{
	int i;
	int x=0;
	cin >> n;
	for(i=0;i<=n;i++)
		cin >> s[i];
	dfs(0);
	while(l[x])
		x=l[x];
	cout << s[x];
	return 0;
}
