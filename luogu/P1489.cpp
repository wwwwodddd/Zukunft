#include <bits/stdc++.h>
using namespace std;
int n, x, s;
bitset<4040> f[101];
int main()
{
	cin >> n;
	f[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
		for (int j = n / 2; j > 0; j--)
		{
			f[j] |= f[j-1] << x;
		}
	}
	for (int i = 0; i <= s / 2; i++)
	{
		if (f[n / 2][s / 2 - i] || f[n / 2][s - s / 2 + i])
		{
			printf("%d %d\n", s / 2 - i, s - s / 2 + i);
			break;
		}
	}
	return 0;
}