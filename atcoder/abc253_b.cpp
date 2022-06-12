#include <bits/stdc++.h>
using namespace std;
int n, m, xa, ya, xb, yb;
string s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'o')
			{
				xb = xa;
				yb = ya;
				xa = i;
				ya = j;
			}
		}
	}
	cout << abs(xa - xb) + abs(ya - yb) << endl;
	return 0;
}
