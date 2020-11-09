#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		bitset<200> f;
		f[0] = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			x = (x % m + m) % m;
			f = f << x | f << m - x;
			f |= f >> m;
		}
		puts(f[0] ? "Divisible" : "Not divisible");
	}
	return 0;
}