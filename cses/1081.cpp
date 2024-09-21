#include <bits/stdc++.h>
using namespace std;
int v[1000020];
int n, x, m = 1000000;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v[x]++;
	}
	for (int i = m; i > 0; i--)
	{
		int c = 0;
		for (int j = i; j <= m; j += i)
		{
			c += v[j];
		}
		if (c >= 2)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}