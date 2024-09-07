#include <bits/stdc++.h>
using namespace std;
int n, k;
int h[100020];
int f[100020];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	f[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		f[i] = 1e9;
		for (int j = 1; j <= k && j < i; j++)
		{
			f[i] = min(f[i], f[i - j] + abs(h[i] - h[i - j]));
		}
	}
	cout << f[n] << endl;
	return 0;
}