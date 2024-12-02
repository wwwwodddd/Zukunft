#include <bits/stdc++.h>
using namespace std;
int n, m, a1, b1, a2, b2;
int a[120];
bool ok()
{
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != i)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> n >> m >> a1 >> b1 >> a2 >> b2;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		reverse(a + a1, a + b1 + 1);
		reverse(a + a2, a + b2 + 1);
		if (ok())
		{
			m %= i;
			m += i;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}