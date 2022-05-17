#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, f[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> q;
	for (int i = 0; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		f[F(x - 1)] = F(y);
	}
	cout << (F(0) == F(n) ? "Yes" : "No") << endl;
	return 0;
}