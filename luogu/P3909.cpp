#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, x;
long long a, b, c;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		c = (c + b * x) % p;
		b = (b + a * x) % p;
		a = (a + x) % p;
	}
	printf("%lld\n", c * 6 % p);
	return 0;
}