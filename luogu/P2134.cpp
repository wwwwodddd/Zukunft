#include <bits/stdc++.h>
using namespace std;
long long n, p, q, x, y, z;
int main()
{
	cin >> n >> p >> q;
	z = n * q;
	for (int i = 0; i <= n; i++)
	{
		x = (n - i) / (i + 1);
		y = (n - i) % (i + 1);
		z = min(z, x * x * (i + 1 - y) * p + (x + 1) * (x + 1) * y * p + i * q);
	}
	cout << z << endl;
	return 0;
}