#include <bits/stdc++.h>
using namespace std;
string s[2020];
int n, f[2020], z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < i; j++)
		{
			if (s[j] == s[i].substr(0, s[j].size()))
			{
				f[i] = max(f[i], f[j]);
			}
		}
		z = max(z, ++f[i]);
	}
	printf("%d\n", z);
	return 0;
}