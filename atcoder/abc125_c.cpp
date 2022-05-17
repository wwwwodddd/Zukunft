#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[100020];
int f[100020];
int g[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[i] = __gcd(f[i - 1], a[i]);
	}
	for (int i = n; i > 0; i--)
	{
		g[i] = __gcd(g[i + 1], a[i]);
		z = max(z, __gcd(f[i - 1], g[i + 1]));
	}
	cout << z << endl;
	return 0;
}
