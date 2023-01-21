#include <bits/stdc++.h>
using namespace std;
long n;
long p[600020];
long z[600020];
void gan(int k)
{
	z[k - ((n + 1) / 2 - 1)] += ((n + 1) / 2 - 1);
	z[k - ((n + 1) / 2 - 2)] += (-(n + 1) / 2);
	z[k + 1] += 1;

	z[k + 1] += 1;
	z[k + n / 2 + 1] -= n / 2 + 1;
	z[k + n / 2 + 2] += n / 2;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		int k = (p[i] - i + n) % n;
		gan(k + n);
	}
	for (int i = 1; i < 3 * n; i++)
	{
		z[i] += z[i - 1];
	}
	for (int i = 1; i < 3 * n; i++)
	{
		z[i] += z[i - 1];
	}
	for (int i = n; i < 3 * n; i++)
	{
		z[i % n] += z[i];
	}
	cout << *min_element(z, z + n) << endl;
	return 0;
}

// 0 0 0 1 2 3 4 5  0 0 0 0
// 0 0 0 1 1 1 1 1 -5 0 0 0
// 0 0 0 1 0 0 0 0 -6 5 0 0

// 0 0 0 5  4  3  2  1  0 0 0 0
// 0 0 0 5 -1 -1 -1 -1 -1 0 0 0
// 0 0 0 5 -6  0  0  0  0 1 0 0
