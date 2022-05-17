#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int d[60];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < 2 * m; i++)
	{
		cin >> x;
		d[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << d[i] << endl;
	}
	return 0;
}
