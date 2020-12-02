#include <bits/stdc++.h>
using namespace std;
long long n, f[2000020], z;
int main()
{
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		f[i] = n / i * (n / i);
		for (int j = i + i; j <= n; j += i)
		{
			f[i] -= f[j];
		}
		z += (f[i] - 1) / 2 * i;
	}
	cout << z << endl;
	return 0;
}