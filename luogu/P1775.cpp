#include <bits/stdc++.h>
using namespace std;
int n;
int s[320];
int f[320][320];
int p[320][320];
int main()
{
	cin >> n;
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
		f[i][i] = 0;
		p[i][i] = i;
	}
	for (int j = 1; j <= n; j++)
	{
		for (int i = j; i > 0; i--)
		{
//			for (int k = i; k < j; k++)
			for (int k = p[i][j - 1]; k < j && k <= p[i + 1][j]; k++)
			{
				if (f[i][j] > f[i][k] + f[k + 1][j] + s[j] - s[i - 1])
				{
					f[i][j] = f[i][k] + f[k + 1][j] + s[j] - s[i - 1];
					p[i][j] = k;
				}
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
