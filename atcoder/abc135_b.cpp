#include <bits/stdc++.h>
using namespace std;
int n, x, c;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x != i)
		{
			c++;
		}
	}
	cout << (c > 2 ? "NO" : "YES") << endl;
	return 0;
}
