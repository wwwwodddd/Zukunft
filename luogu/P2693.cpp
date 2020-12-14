#include <bits/stdc++.h>
using namespace std;
int n, a[3], b[3];
int main()
{
	cin >> n;
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> b[i];
	}
	if (n < 5)
	{
		cout << n * n * n << endl;
	}
	else
	{
		int z = 1;
		for (int i = 0; i < 3; i++)
		{
			int d = abs(a[i] - b[i]);
			d = min(d, n - d);
			z *= max(5 - d, 0);
		}
		cout << 250 - z << endl;
	}
	return 0;
}