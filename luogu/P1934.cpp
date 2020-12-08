#include <bits/stdc++.h>
using namespace std;
int n, t;
long long a[1020];
long long f[1020];
int main()
{
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = f[i - 1] + a[i] * n * n;
		for (int j = i - 1, s = a[i]; j > 0; j--)
		{
			s += a[j];
			if (a[i] + a[j] <= t)
			{
				f[i] = min(f[i], f[j - 1] + (a[i] + a[j]) * s);
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}