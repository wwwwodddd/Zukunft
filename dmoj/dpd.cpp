#include <bits/stdc++.h>
using namespace std;
int n, m, w, v;
long long f[100001];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;
		for (int j = m; j >= w; j--)
		{
			f[j] = max(f[j], f[j - w] + v);
		}
	}
	cout << f[m] << endl;
	return 0;
}