#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int z = -1;
		for (int i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (i >= 6)
				{
					z = max(z, n / i);
				}
				if (n / i >= 6)
				{
					z = max(z, i);
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}
