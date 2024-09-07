#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int c0 = 0;
		int c1 = 0;
		int c2 = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x != i + 1)
			{
				c0++;
			}
			if (x != n - i)
			{
				c1++;
			}
			if (x != i + 1 && x != n - i)
			{
				c2++;
			}
		}
		if (c0 <= c1 - c2)
		{
			cout << "First" << endl;
		}
		else if (c1 < c0 - c2)
		{
			cout << "Second" << endl;
		}
		else
		{
			cout << "Tie" << endl;
		}
	}
	return 0;
}
