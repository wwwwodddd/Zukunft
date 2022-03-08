#include <bits/stdc++.h>
using namespace std;
int n, m, x;
map<int, int> c;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x]++;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		c[x]--;
	}
	for (pair<int, int> i: c)
	{
		if (i.second < 0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
