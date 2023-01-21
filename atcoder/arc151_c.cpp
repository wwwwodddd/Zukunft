#include <bits/stdc++.h>
using namespace std;
int m;
long long n, z;
long long x[200020];
int y[200020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x[i] >> y[i];
		if (i > 0 && y[i - 1] == y[i])
		{
			z ^= 1;
		}
	}
	if (m > 0)
	{
		z ^= x[0] - 1;
		z ^= n - x[m - 1];
	}
	else
	{
		z = n & 1;
	}
	cout << (z ? "Takahashi" : "Aoki") << endl;
	return 0;
}