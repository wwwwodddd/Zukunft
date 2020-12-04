#include <bits/stdc++.h>
using namespace std;
int n, s, x, p[7], z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		s += x;
		s %= 7;
		if (s > 0 && p[s] == 0)
		{
			p[s] = i;
		}
		else
		{
			z = max(z, i - p[s]);
		}
	}
	printf("%d\n", z);
	return 0;
}