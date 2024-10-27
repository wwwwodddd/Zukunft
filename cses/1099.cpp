#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int x, s = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (i & 1)
			{
				s ^= x;
			}
		}
		cout << (s ? "first" : "second") << endl;
	}
	return 0;
}