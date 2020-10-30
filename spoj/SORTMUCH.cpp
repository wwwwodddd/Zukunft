#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		long long n, L = 0, R;
		scanf("%lld", &n);
		R = n + 1;
		while (L < R - 1)
		{
			long long M = (L + R) / 2;
			if (log(M) / log(3) * M > n)
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		printf("%lld\n", L);
	}
	return 0;
}