#include <bits/stdc++.h>
using namespace std;
int t, n;
int read()
{
	int n=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		;
	for(;isdigit(c);c=getchar())
		n=n*10+c-'0';
	return n;
}
int main()
{
	t = read();
	for (int tt = 0; tt < t; tt++)
	{
		n = read();
		int s = 0;
		for (int i = 0; i < n; i++)
		{
			s |= read();
		}
		for (int i = 1; i < n; i++)
		{
			s = s * 2 % 998244353;
		}
		printf("%d\n", s);
	}
	return 0;
}