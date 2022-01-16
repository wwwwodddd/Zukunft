#include <bits/stdc++.h>
using namespace std;
int n, f[100001];
int main()
{
	cin >> n;
	f[0] = 0;
	for (int j = 1; j <= n; j++)
	{
		f[j] = j;
		for (int i = 1; i <= j; i *= 6)
		{
			f[j] = min(f[j], f[j - i] + 1);
		}
		for (int i = 1; i <= j; i *= 9)
		{
			f[j] = min(f[j], f[j - i] + 1);
		}
	}
	cout << f[n] << endl;
	return 0;
}
