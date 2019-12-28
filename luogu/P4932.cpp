#include <bits/stdc++.h>
using namespace std;
unsigned long long X, ans[2];
unsigned n, a, b, c, d;
int main()
{
	scanf("%u%u%u%u%u%llu", &n, &a, &b, &c, &d, &X);
	for (unsigned i = 0; i < n; i++)
	{
		X = (a * X % d * X + b * X + c) % d;
		ans[__builtin_parity(X)]++;
	}
	printf("%llu\n", ans[0] * ans[1]);
	return 0;
}