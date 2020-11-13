#include <bits/stdc++.h>
using namespace std;
int l, n;
long long z, rf, rb;
int x[100020];
int c[100020];
int main()
{
	cin >> l >> n >> rf >> rb;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> c[i];
	}
	for (int i = n - 1; i > 0; i--)
	{
		c[i] = max(c[i], c[i + 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		z += (x[i] - x[i - 1]) * (rf - rb) * c[i];
	}
	cout << z << endl;
	return 0;
}