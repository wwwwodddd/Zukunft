#include <bits/stdc++.h>
using namespace std;
const int M = 3000;
int n, m, l, x, y;
int f[M + 20];
int main()
{
	cin >> m >> l >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		x /= 1000;
		for (int j = x; j <= M; j++)
		{
			f[j] = max(f[j], f[j - x] + y);
		}
	}
	for (int i = 0; i < l; i++)
	{
		m += f[m / 1000];
	}
	cout << m << endl;
}