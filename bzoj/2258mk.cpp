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
int n=50000,m=400;
int main()
{
	freopen("c.in","w",stdout);
	for(int i=0;i<n;i++)
		printf("%c",'a'+(rand()%8==0));
	puts("");
	printf("%d\n",m);
	for(int i=0;i<m;i++)
	{
		if(rand()&1)
			printf("I %c %d\n",'a'+(rand()%8==0),rand()%(n+3)+1);
		else
			printf("Q %d %d\n",rand()%n+1,rand()%n+1);
	}

}
