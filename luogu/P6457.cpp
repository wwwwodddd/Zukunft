#include <bits/stdc++.h>
using namespace std;
int n;
int a[220];
int f[220][220];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] %= 2;
		a[n + i] = a[i];
	}
	for (int i = 0; i < 2 * n; i++)
	{
		f[i][i] = a[i];
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 0; i + l <= 2 * n; i++)
		{
			int j = i + l - 1;
			f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1]);
		}
	}
	int z = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] - f[i + 1][i + n - 1] > 0)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}