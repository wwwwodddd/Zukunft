#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int f[100020];
int g[100020];
int h[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		f[i] = max(g[i - 1], h[i - 1]) + a;
		g[i] = max(f[i - 1], h[i - 1]) + b;
		h[i] = max(f[i - 1], g[i - 1]) + c;
	}
	cout << max(f[n], max(g[n], h[n])) << endl;
	return 0;
}