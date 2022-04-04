#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int f[120][1020];
int s[120][1020];
int n;
int a[120];
int gan()
{
	memset(f, 0, sizeof f);
	memset(s, 0, sizeof s);
	f[0][0] = 1;
	for (int j = 0; j < 1010; j++)
	{
		s[0][j + 1] = (s[0][j] + f[0][j]) % p;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= a[i]; j++)
		{
			f[i][j] = s[i - 1][a[i] - j + 1];
		}
		for (int j = 0; j < 1010; j++)
		{
			s[i][j + 1] = (s[i][j] + f[i][j]) % p;
		}
	}
	return f[n][0];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = gan();
	while (n % 2 == 1)
	{
		int f = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i]--;
			if (a[i] < 0)
			{
				f = 1;
				break;
			}
		}
		if (f == 1)
		{
			break;
		}
		ans = (ans + gan()) % p;
	}
	cout << ans << endl;
	return 0;
}
