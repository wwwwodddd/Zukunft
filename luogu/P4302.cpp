#include <bits/stdc++.h>
using namespace std;
string s;
int f[120][120];
int lcp[120][120];
bool check(int i, int j, int k)
{
	return lcp[i][i + k] >= j - i - k;
}
int digits(int n)
{
	int d = 0;
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return d;
}
int main()
{
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		for (int j = s.size() - 1; j >= 0; j--)
		{
			if (s[i] == s[j])
			{
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			}
			else
			{
				lcp[i][j] = 0;
			}
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < s.size(); i++)
	{
		f[i][i + 1] = 1;
	}
	for (int l = 2; l <= s.size(); l++)
	{
		for (int i = 0; i + l <= s.size(); i++)
		{
			int j = i + l;
			for (int k = i + 1; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
			for (int k = 1; k <= l; k++)
			{
				if (l % k == 0 && check(i, j, k))
				{
					f[i][j] = min(f[i][j], f[i][i + k] + 2 + digits(l / k));
				}
			}
		}
	}
	cout << f[0][s.size()] << endl;
	return 0;
}