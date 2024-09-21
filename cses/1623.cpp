#include <bits/stdc++.h>
using namespace std;
int n;
int p[20];
int main()
{
	cin >> n;
	long long s = 0, z = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		s += p[i];
	}
	z = s;
	for (int i = 0; i < 1 << n; i++)
	{
		long long t = 0;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				t += p[j];
			}
		}
		z = min(z, abs(s - t - t));
	}
	cout << z << endl;
	return 0;
}