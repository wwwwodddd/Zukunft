#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	bool f = true;
	for (int i = 0; i < s.size();)
	{
		if (i + 1 < s.size() && s[i] == 'c' && s[i + 1] == 'h')
//		if (s.substr(i, 2) == "ch")
		{
			i += 2;
		}
		else if (s[i] == 'o' || s[i] == 'k' || s[i] == 'u')
		{
			i++;
		}
		else
		{
			f = false;
			break;
		}
	}
	if (f)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
