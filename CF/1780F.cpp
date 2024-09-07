#include <bits/stdc++.h>
using namespace std;
int n, m = 300000;
int c[300020];
int s[300020];
long long f[300020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		c[x]++;
	}
	for (int i = 1; i <= m; i++)
	{
		s[i] = s[i - 1] + c[i];
	}
	for (int i = 1; i <= m; i++)
	{
		long long cnt = 0;
		for (int z = i; z <= m; z += i)
		{
			if (c[z])
			{
				f[i] += s[z - 1] * cnt;
				cnt++;
			}
		}
		cnt = 0;
		for (int z = i; z <= m; z += i)
		{
			if (c[z])
			{
				cnt++;
			}
		}
		for (int x = i; x <= m; x += i)
		{
			if (c[x])
			{
				cnt--;
				f[i] -= s[x] * cnt;
			}
		}
	}
	for (int i = m; i > 0; i--)
	{
		for (int j = i + i; j <= m; j += i)
		{
			f[i] -= f[j];
		}
	}
	cout << f[1] << endl;
	return 0;
}
