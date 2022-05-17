#include <bits/stdc++.h>
using namespace std;
int n;
long long a, s, mx, x;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &x);
		mx = max(mx, x);
		a += x;
		s += a;
		printf("%lld\n", s + i * mx);
	}
	return 0;
}
