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
int n,m,x,y,z;
int RD()
{
	return rand()<<15|rand();
}
int main()
{
	freopen("c.in","w",stdout);
	srand(time(0));
	n=100000;
	m=100000;
	printf("%d\n",n);
	fo(i,n-1)
		printf("%d ",rand());
	fo(i,n)
		printf("%d ",rand());
	fo(i,n-1)
		printf("%d ",rand());
	puts("");
	printf("%d\n",m);
	for(int i=0;i<m;i++)
	{
		int o=rand()&1;
		printf("%d ",o);
		if(o)
		{
			x=rand()%(2*n)+1;
			y=rand()%(2*n)+1;
			printf("%d %d\n",x,y);
		}
		else
		{
			x=rand()%3;
			y=rand()%(n-1)+1;
			z=rand();
			printf("%d %d %d\n",x,y,z);
		}
	}
}
