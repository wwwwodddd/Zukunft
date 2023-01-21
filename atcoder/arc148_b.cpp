#include <bits/stdc++.h>
using namespace std;
string F(const string &s)
{
	string t;
	for (unsigned i = s.size(); i--;)
	{
		if (s[i] == 'd')
		{
			t += 'p';
		}
		else
		{
			t += 'd';
		}
	}
	return t;
}
int n, l;
string s, z;
int main()
{
	cin >> n >> s;
	while (l < n && s[l] == 'd')
	{
		l++;
	}
	z = s;
	for (int r = l + 1; r <= n; r++)
	{
		z = min(z, s.substr(0, l) + F(s.substr(l, r - l)) + s.substr(r));
	}
	cout << z << endl;
	return 0;
}