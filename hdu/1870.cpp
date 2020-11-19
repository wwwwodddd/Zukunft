#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char s[10020];
int main()
{
	while(scanf("%s",s)+1)
	{
		int z=0;
		for(int i=0;s[i]!='B';i++)
			z+=(s[i]=='(')-(s[i]==')');
		printf("%d\n",z);
	}
}
