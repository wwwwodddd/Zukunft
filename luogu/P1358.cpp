#include <bits/stdc++.h>
using namespace std;
const int p = 10007;
int n, m, x, z;
int f[10020];
int v[10020];
int main()
{
	cin >> n >> m;
	f[0] = 1;
	v[0] = v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = v[p % i] * (p - p / i) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1] * i % p;
		v[i] = v[i - 1] * v[i] % p;
	}
	z = f[n];
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		z = z * v[x] % p;
		n -= x;
	}
	z = z * v[n] % p;
	cout << z << endl;
	return 0;
}