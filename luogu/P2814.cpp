#include <bits/stdc++.h>
using namespace std;
map<string, string> f;
string a, b;
char c;
string F(string s)
{
	while (f.find(s) != f.end())
	{
		s = f[s];
	}
	return s;
}
int main()
{
	while (true)
	{
		cin >> c;
		if (c == '#')
		{
			cin >> a;
		}
		else if (c == '+')
		{
			cin >> b;
			f[b] = a;
		}
		else if (c == '?')
		{
			cin >> b;
			cout << b << ' ' << F(b) << endl;
		}
		else
		{
			break;
		}
	}
}