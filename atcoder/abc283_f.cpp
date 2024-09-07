#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int z = 2 * n;
		for (int j = 1; j <= z; j++)
		{
			if (i - j > 0)
			{
				z = min(z, abs(a[i] - a[i - j]) + j);
			}
			if (i + j <= n)
			{
				z = min(z, abs(a[i] - a[i + j]) + j);
			}
		}
		cout << z << " ";
	}
	return 0;
}
