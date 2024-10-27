#include <bits/stdc++.h>
using namespace std;
int n, x, l, r;
long long s[200020];
long long z = -1e18;
int q[200020], bb, ff;
int main()
{
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
		if (i >= l)
		{
			while (bb < ff && s[q[ff - 1]] > s[i - l])
			{
				ff--;
			}
			q[ff++] = i - l;
		}
		while (bb < ff && q[bb] < i - r)
		{
			bb++;
		}
		if (bb < ff)
		{
			z = max(z, s[i] - s[q[bb]]);
		}
	}
	cout << z << endl;
	return 0;
}