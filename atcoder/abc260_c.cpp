#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long f[20];
long long g[20];
int main()
{
	cin >> n >> x >> y;
	f[1] = 0;
	g[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		g[i] = f[i - 1] + y * g[i - 1];
		f[i] = f[i - 1] + x * g[i];
	}
	cout << f[n] << endl;
	return 0;
}
