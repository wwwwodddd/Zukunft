#include <bits/stdc++.h>
using namespace std;
int n, x;
long long s;
int main()
{
	scanf("%d", &n);
	s = n * (n + 1LL) / 2;
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &x);
		s -= x;
	}
	printf("%lld\n", s);
	return 0;
}