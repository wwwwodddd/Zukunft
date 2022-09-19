#include <bits/stdc++.h>
using namespace std;
long long t, x, s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> x >> s;
		int z = 2;
		if (x >= 3)
		{
			z++;
		}
		if (x >= 5)
		{
			z++;
		}
		if (s >= 10000000)
		{
			z++;
		}
		if (s >= 20000000)
		{
			z++;
		}
		if (s >= 40000000)
		{
			z++;
		}
		if (s >= 60000000)
		{
			z++;
		}
		cout << z << endl;
	}
	return 0;
}