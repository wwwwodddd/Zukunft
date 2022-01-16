#include <bits/stdc++.h>
using namespace std;
int n, k, z;
int t[9][9];
int p[9];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		for (int j = 1; j <= n; j++)
		{
			cin >> t[i][j];
		}
	}
	do
	{
		int s = t[p[n]][p[1]];
		for (int i = 1; i < n; i++)
		{
			s += t[p[i]][p[i + 1]];
		}
		if (s == k)
		{
			z++;
		}
	}
	while (next_permutation(p + 2, p + n + 1));
	cout << z << endl;
	return 0;
}
