#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
	cin >> n >> k;
	if (k == 1)
	{
		cout << n / 2 << endl;
	}
	else if (k == 2)
	{
		long long L = -1, R = 1e9;
		while (L < R - 1)
		{
			long long M = (L + R) / 2;
			if (2 * M * M + 1 < n)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		cout << R << endl;
	}
	else if (k == 3)
	{
		long long L = -1, R = 1e6;
		while (L < R - 1)
		{
			long long M = (L + R) / 2;
			if ((((4 * M - 6) * M + 8) * M + 3) / 3 < n)
			{
				L = M;
			}
			else
			{
				R = M;
			}
		}
		cout << R << endl;
	}
	else
	{
		vector<long long> f(k + 1, 1);
		int z = 0;
		while (f[k] < n)
		{
			z += 1;
			for (int i = k; i > 0; i--)
			{
				f[i] += f[i - 1] * 2;
			}
		}
		cout << z << endl;
	}
	return 0;
}