#include <bits/stdc++.h>
using namespace std;
map<string, int> f;
int F(string s)
{
	if (f.find(s) != f.end())
	{
		return f[s];
	}
	f[s] = 1;
	int l = s.size();
	for (int i = 1; i * 2 < l; i++)
	{
		if (s.substr(0, i) == s.substr(l - i, i))
		{
			f[s] += F(s.substr(i, l - i)) + F(s.substr(0, l - i));
		}
		if (s.substr(0, i) == s.substr(i, i))
		{
			f[s] += F(s.substr(i, l - i));
		}
		if (s.substr(l - 2 * i, i) == s.substr(l - i, i))
		{
			f[s] += F(s.substr(0, l - i));
		}
	}
	return f[s] %= 2014;
}
int main()
{
	string s;
	cin >> s;
	cout << ((F(s) + 2013) % 2014) << endl;
	return 0;
}