#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[200020];
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
		long long s = 1;
		bool f = (a[0] == 1);
		for (int i = 1; i < n && f; i++)
		{
			if (s < a[i])
			{
				f = false;
			}
			s += a[i];
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}