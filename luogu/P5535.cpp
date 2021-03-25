#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool P(long long x)
{
	for (long long i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%lld%lld", &n, &k);
	puts(P(k + 1) && 2 * k >= n ? "1" : "2");
	return 0;
}