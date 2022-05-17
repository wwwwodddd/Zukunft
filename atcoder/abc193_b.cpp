#include <bits/stdc++.h>
using namespace std;
int n, a, p, x, z = 2e9;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> p >> x;
		if (x > a)
		{
			z = min(z, p);
		}
	}
	if (z == 2e9)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}
