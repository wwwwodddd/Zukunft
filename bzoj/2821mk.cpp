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
int n,m,t;
int main()
{
	freopen("c.in","w",stdout);
	n=1000,t=1000,m=100;
/*
	n=10,t=10,m=3;
//*/
	srand(time(0));
	printf("%d %d %d\n",n,m,t);
	fo(i,n)
		printf("%d ",rand()%m+1);
	puts("");
	fo(i,t)
		printf("%d %d\n",rand()%n,rand()%n);
	return 0;
}
