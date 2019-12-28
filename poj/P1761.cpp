#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int>m;
int a[100][20],b[100][20];
int t,n;
string r,s,u;
int Q(string s)
{
	if(m.count(s))
		return m[s];
	int t=m.size();
	return m[s]=t;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>t>>s>>r>>u;
		int f=Q(s),g=r[0]-'A';
		if(b[f][g])
			continue;
		a[f][g]++;
		if(u[0]=='A')
			b[f][g]=t;
	}
	for(int i=0;i<9;i++)
	{
		int x=0,y=0,z=0;
		for(int j=0;j<m.size();j++)
			if(b[j][i])
				x++,y+=a[j][i],z+=b[j][i];
		printf("%c %d",i+'A',x);
		if(y)
			printf(" %.2f %.2f",(double)y/x,(double)z/x);
		puts("");
	}
	return 0;
}
