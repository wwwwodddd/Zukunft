#include <bits/stdc++.h>
using namespace std;
string s;
bool ok()
{
	if (s[0] != 'A')
	{
		return false;
	}
	int c = 0;
	for (int i = 2; i < s.size() - 1; i++)
	{
		if (s[i] == 'C')
		{
			c++;
		}
	}
	if (c != 1)
	{
		return false;
	}
	int d = 0;
	for (char i: s)
	{
		if (isupper(i))
		{
			d++;
		}
	}
	return d == 2;
}
int main()
{
	cin >> s;
	cout << (ok() ? "AC" : "WA") << endl;
	return 0;
}
