#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld", &n);
		n--;
		long long L = 0, R = 2e9;
		while (L < R - 1)
		{
			long long M = (L + R) / 2;
			if (M * (M + 1) / 2 < n)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		printf("%d\n", R * (R + 1) / 2 == n);
	}
	return 0;
}