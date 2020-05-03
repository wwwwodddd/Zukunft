#include <bits/stdc++.h>
using namespace std;
bitset<5020> f[52];
int n, s, x;
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
			f[j] |= f[j - 1] << x;
		}
	}
	for (int i = s / 2; i >= 0; i--)
	{
		if (f[n / 2][i])
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}