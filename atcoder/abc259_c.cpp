#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
	cin >> s >> t;
	for (int i = 0, j = 0; i < t.size(); i++)
	{
		if (j == s.size() || s[j] != t[i])
		{
			if (j < 2 || s[j - 1] != t[i] || s[j - 2] != t[i])
			{
				cout << "No" << endl;
				return 0;
			}
		}
		else
		{
			j++;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
