#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t;
long long n, l;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld%lld", &n, &l);
		if (n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		long long b = 1;
		while (b * 2 <= n)
		{
			b = b * 2;
		}
		cout << (l / 2) * (l - l / 2) % p * (b * 2 - 1) % p << endl;
	}
	return 0;
}
