#include <bits/stdc++.h>
using namespace std;
int n, x, g;
int c[1000020];
int MAIN()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x]++;
		g = __gcd(g, x);
	}
	if (g > 1)
	{
		cout << "not coprime" << endl;
		return 0;
	}
	for (int i = 2; i < 1000010; i++)
	{
		int s = 0;
		for (int j = i; j < 1000010; j += i)
		{
			s += c[j];
		}
		if (s > 1)
		{
			cout << "setwise coprime" << endl;
			return 0;
		}
	}
	cout << "pairwise coprime" << endl;
	return 0;
}
int main()
{
	return MAIN();
}
