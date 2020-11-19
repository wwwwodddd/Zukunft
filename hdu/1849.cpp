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
int n,x,z;
int main()
{
	for(;scanf("%d",&n),n;puts(z?"Rabbit Win!":"Grass Win!"),z=0)
		for(;n--;z^=x)
			scanf("%d",&x);
}
