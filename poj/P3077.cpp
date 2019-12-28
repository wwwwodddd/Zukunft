#include<iostream>
#include<stdio.h>
using namespace std;
int L(int x)
{
	int re=0;
	while(x>0)
	{
		x/=10;
		re++;
	}
	return re;
}
int C(int x)
{
	int re=0;
	while(x>0)
	{
		x--;
		re=re*10+5;
	}
	return re;
}
int T(int x)
{
	int re=1;
	while(x>0)
	{
		x--;
		re=re*10;
	}
	return re;
}
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(n+C(L(n)-1))/T(L(n)-1)*(T(L(n)-1)));
	}
	return 0;
}
