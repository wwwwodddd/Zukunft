#include <bits/stdc++.h>
using namespace std;
int k[3], n, x;
int a[200020];
int f[200020];
int main()
{
	cin >> k[0] >> k[1] >> k[2];
	n = k[0] + k[1] + k[2];
	memset(f, 0x3f, sizeof f);
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < k[j]; i++)
		{
			cin >> a[i];
		}
		sort(a, a + k[j]);
		for (int i = 0; i < k[j]; i++)
		{
			*upper_bound(f, f + n, a[i]) = a[i];
		}
	}
	cout << (f + n - lower_bound(f, f + n, 0x3f3f3f3f)) << endl;
	return 0;
}