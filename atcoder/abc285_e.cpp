#include <bits/stdc++.h>
using namespace std;
int n;
int a[5020];
long long b[5020];
long long f[5020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] + a[(i + 1) / 2];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			f[i] = max(f[i], f[j] + b[i - j - 1]);
		}
	}
	cout << f[n] << endl;
	return 0;
}