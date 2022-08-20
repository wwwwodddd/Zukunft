#include <bits/stdc++.h>
using namespace std;
int n;
string s[60], t;
char v[33];
int main()
{
	memset(v, '*', sizeof v);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cin >> t;
	for (int i = 0; i < n; i++)
	{
		if (s[i].substr(0, t.size()) == t)
		{
			v[s[i][t.size()] - 'A' + 3] = s[i][t.size()];
		}
	}
	for (int i = 0; i < 32; i++)
	{
		cout << v[i];
		if (i % 8 == 7)
		{
			cout << endl;
		}
	}
	return 0;
}
