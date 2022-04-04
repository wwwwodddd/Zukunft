#include <bits/stdc++.h>
using namespace std;
int n, x, c, z;
string s;
map<int, int> g;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> x;
		if (s == "G")
		{
			c++;
			g[x]--;
		}
		else
		{
			g[x + 1]++;
		}
	}
	z = c;
	for (pair<int, int> i: g)
	{
		c += i.second;
		z = min(z, c);
	}
	cout << z << endl;
	return 0;
}