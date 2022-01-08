#include <bits/stdc++.h>
using namespace std;
string s;
int zuo()
{
	if (s.size() & 1)
	{
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (i & 1)
		{
			if (s[i] != 'i')
			{
				return 0;
			}
		}
		else
		{
			if (s[i] != 'h')
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	cin >> s;
	cout << (zuo() ? "Yes" : "No") << endl;
	return 0;
}
