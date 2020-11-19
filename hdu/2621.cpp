#include<stdio.h>
#include<iostream>
using namespace std;
long long z,n,m;
int main()
{
	for(;scanf("%I64d %I64d",&n,&m),n+m;)
	{
		if(n>m)
			swap(n,m);
		z=1;
		for(int i=0;i<n;i++)
			z=z*(n+m-i)/(i+1);
		printf("%I64d\n",z);
	} 
	return 0;
}
