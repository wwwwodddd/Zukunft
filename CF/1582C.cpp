#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int zuo(string s, char c)
{
	int l = 0, r = s.size() - 1, z = 0;
	while (l < r)
	{
		if (s[l] == s[r])
		{
			l++;
			r--;
		}
		else if (s[l] == c)
		{
			l++;
			z++;
		}
		else if (s[r] == c)
		{
			r--;
			z++;
		}
		else
		{
			return s.size();
		}
	}
	return z;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> s;
		int z = s.size();
		for (char c = 'a'; c <= 'z'; c++)
		{
			z = min(z, zuo(s, c));
		}
		if (z == s.size())
		{
			z = -1;
		}
		cout << z << endl;
	}
	return 0;
}
