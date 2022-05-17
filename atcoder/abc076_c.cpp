#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
	cin >> s >> t;
	for (int i = s.size() - t.size(), j; i >= 0; i--)
	{
		for (j = 0; j < t.size(); j++)
		{
			if (s[i + j] != '?' && s[i + j] != t[j])
			{
				break;
			}
		}
		if (j == t.size())
		{
			for (j = 0; j < t.size(); j++)
			{
				s[i + j] = t[j];
			}
			for (j = 0; j < s.size(); j++)
			{
				if (s[j] == '?')
				{
					s[j] = 'a';
				}
			}
			cout << s << endl;
			return 0;
		}
	}
	cout << "UNRESTORABLE" << endl;
	return 0;
}
