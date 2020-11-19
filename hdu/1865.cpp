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
int f[300]={1,1},t;
char s[320];
int main()
{
	for(int i=2;i<220;i++)
		f[i]=f[i-1]+f[i-2];
	for(scanf("%d",&t);t--;)
	{
		scanf("%s",s);
		printf("%d\n",f[strlen(s)]);
	}
}
