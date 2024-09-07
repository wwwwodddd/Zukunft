#include <bits/stdc++.h>
using namespace std;
int t, n, q;
long long s[200020], l, r, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> q;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
			s[i] += s[i - 1];
		}
		for (int i = 0; i < q; i++)
		{
			cin >> l >> r >> k;
			puts(((s[l - 1] + s[n] - s[r] + (r - l + 1) * k) % 2) ? "YES" : "NO");
		}
	}
	return 0;
}