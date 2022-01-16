#include <bits/stdc++.h>
using namespace std;
int v[120];
int x, n, a;
int main()
{
	cin >> x >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[a] = 1;
	}
	for (int i = 0; i < 60; i++)
	{
		if (!v[x - i])
		{
			cout << x - i << endl;
			break;
		}
		if (!v[x + i])
		{
			cout << x + i << endl;
			break;
		}
	}
	return 0;
}
