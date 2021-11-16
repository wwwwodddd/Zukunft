#include <bits/stdc++.h>
using namespace std;
int n, x, y, c;
int d[100020];
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		d[x]++;
		d[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 1)
		{
			c++;
		}
	}
	cout << (c == n - 1 ? "Yes" : "No") << endl;
	return 0;
}
