#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int f = 0;
		for (int i = 1; i * i + i + i + 1 < n; i++)
		{
			if (n % (i * i + i + i + 1) == 0)
			{
				f = 1;
				break;
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}