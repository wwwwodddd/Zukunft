#include <bits/stdc++.h>
using namespace std;
int l, r, z;
int S(long long x)
{
	int s = 0;
	for (; x > 0; x /= 10)
	{
		s += x % 10;
	}
	return s;
}
void dfs(long long x)
{
	if (x <= r && S(x * x) == S(x) * S(x))
	{
		if (l <= x)
		{
			z++;
		}
		for (int i = x == 0; i < 4; i++)
		{
			dfs(x * 10 + i);
		}
	}
}
int main()
{
	cin >> l >> r;
	dfs(0);
	cout << z << endl;
	return 0;
}