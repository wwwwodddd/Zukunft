#include <bits/stdc++.h>
using namespace std;
int n, l;
int a[100020];
long long s[100020];
int main()
{
	cin >> n >> l;
	int L = 0, R = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] *= 1000;
		R = max(R, a[i]);
	}
	R++;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		long long t = 0;
		long long z = -1;
		for (int i = 1; i <= n; i++)
		{
			s[i] = s[i - 1] + a[i] - M;
			if (i >= l)
			{
				t = min(t, s[i - l]);
				z = max(z, s[i] - t);
			}
		}
		if (z >= 0)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	cout << L << endl;
	return 0;
}
