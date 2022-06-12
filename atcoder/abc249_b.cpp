#include <bits/stdc++.h>
using namespace std;
string s;
int v[256], u, l, f = 1;
int main()
{
	cin >> s;
	for (char c: s)
	{
		if (isupper(c))
		{
			u = 1;
		}
		if (islower(c))
		{
			l = 1;
		}
		if (v[c])
		{
			f = 0;
		}
		v[c] = 1;
	}
	if (u && l && f)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
