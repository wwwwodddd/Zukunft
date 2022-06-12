#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[120];
int f[120];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int s = 0, z = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s += a[i];
			f[i] = a[i];
			for (int j = 0; j < i; j++)
			{
				if (a[j] <= a[i])
				{
					f[i] = max(f[i], f[j] + a[i]);
				}
			}
			z = max(z, f[i]);
		}
		cout << s - z << endl;
	}
	return 0;
}
