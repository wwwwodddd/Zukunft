#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int n,m,x,y;
int RD()
{
	return rand()<<15|rand();
}
int main()
{
	freopen("c.in","w",stdout);
	srand(time(0));
	n=100000;
	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%d %d\n",rand(),rand());
	return 0;
}
