#include <bits/stdc++.h>
using namespace std;
long long n, a, b, p, q, r, s;
int main()
{
	cin >> n >> a >> b >> p >> q >> r >> s;
	for (long long i = p; i <= q; i++)
	{
		for (long long j = r; j <= s; j++)
		{
			cout << (a + b == i + j || a - b == i - j ? '#' : '.');
		}
		cout << endl;
	}
	return 0;
}
