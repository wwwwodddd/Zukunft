#include <bits/stdc++.h>
using namespace std;
string a, b, c, s, t;
int x[26], y[26];
int green, yellow;
int main()
{
	cin >> a >> b >> c;
	s = a + b + c;
	cin >> a >> b >> c;
	t = a + b + c;
	for (int i = 0; i < 9; i++)
	{
		if (s[i] == t[i])
		{
			green++;
		}
		else
		{
			x[s[i] - 'A']++;
			y[t[i] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		yellow += min(x[i], y[i]);
	}
	cout << green << endl;
	cout << yellow << endl;
	return 0;
}
