#include <bits/stdc++.h>
using namespace std;
int n, a, b, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (5 * a - 3 * b > 40)
		{
			z++;
		}
	}
	cout << z;
	if (z == n)
	{
		cout << '+';
	}
	return 0;
}
