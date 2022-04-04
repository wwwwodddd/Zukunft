#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int a[20];
string s[20], t, r;
map<string, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		g[s[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> t >> x >> y;
		for (int j = 0; j < y; j++)
		{
			cin >> r;
			a[g[r]] += x / y;
			a[g[t]] -= x / y;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << " " << a[i] << endl;
	}
	return 0;
}
