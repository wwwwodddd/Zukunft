#include <bits/stdc++.h>
using namespace std;
int n, z;
int s[420];
int f[420][420];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		z = max(z, s[i]);
		s[i] += s[i - 1];
		f[i][i] = 1;
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j = i, k = i + l - 1;
			while (j < k)
			{
				if (s[j] - s[i - 1] == s[i + l - 1] - s[k - 1] && f[i][j] && (j + 1 == k || f[j + 1][k - 1]) && f[k][i + l - 1])
				{
					f[i][i + l - 1] = 1;
					z = max(z, s[i + l - 1] - s[i - 1]);
					break;
				}
				if (s[j] - s[i - 1] < s[i + l - 1] - s[k - 1])
				{
					j++;
				}
				else
				{
					k--;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}