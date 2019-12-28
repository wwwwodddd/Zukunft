#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int d[110][110];
string s1[110],s2[110];
int p[110][110], s[100];
int c,c1,c2;
void print(int i,int j)
{
	if(i==0&&j==0);
	else if(p[i][j]==1)
	{
		print(i-1,j-1);
		s[c++]=i;
	}
	else if(p[i][j]==2)
		print(i,j-1);
	else if(p[i][j]==3)
		print(i-1,j);
	return;
}
int main()
{
	while((cin>>s1[++c1]))
	{
		while((cin >> s1[++c1])&&s1[c1]!="#");
		while((cin >> s2[++c2])&&s2[c2]!="#");
		c1--;
		c2--;
		memset(d,0,sizeof(d));
		for(int i=1;i<=c1;i++)
			for(int j=1;j<=c2;j++)
				if(s1[i]==s2[j])
				{
					d[i][j]=d[i-1][j-1]+1;
					p[i][j]=1;
				}
				else
				{
					d[i][j]=max(d[i-1][j],d[i][j-1]);
					if(d[i-1][j]<d[i][j-1])
						p[i][j]=2;
					else
						p[i][j]=3;
				}
		memset(s,0,sizeof(s));
		c=0;
		print(c1,c2);
		for(int i=0;i<c-1;i++)
			cout << s1[s[i]] << ' ';
		cout << s1[s[c-1]] << endl;
		c1=c2=0;
	}
	return 0;
}