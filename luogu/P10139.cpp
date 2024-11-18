#include <bits/stdc++.h>
using namespace std;
long t, n;
long a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		long z = min(a[n - 1], n * (n + 1) / 2);
		long l = n - 1, h = n - 1, d = 0;
		for (long i = 0; i < n; i++)
		{
			d += l;
			l--;
			while (a[i] < d - h)
			{
				d -= h;
				h--;
			}
			if (a[i] < d)
			{
				z = min(z, h * (h + 1) / 2);
			}
		}
		cout << z << endl;
	}
	return 0;
}
