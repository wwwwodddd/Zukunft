#include <bits/stdc++.h>
using namespace std;
int n, a[120];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int z = n, s = 0;
	for (int i = n; i > 0; i--)
	{
		s += a[i];
		if (s < 4)
		{
			z--;
		}
	}
	cout << z << endl;
	return 0;
}
