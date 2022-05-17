#include <bits/stdc++.h>
using namespace std;
int n, f[100001];
int main()
{
	cin >> n;
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 1; i <= n; i *= 6)
	{
		for (int j = i; j <= n; j++)
		{
			f[j] = min(f[j], f[j - i] + 1);
		}
	}
	for (int i = 1; i <= n; i *= 9)
	{
		for (int j = i; j <= n; j++)
		{
			f[j] = min(f[j], f[j - i] + 1);
		}
	}
	cout << f[n] << endl;
	return 0;
}
