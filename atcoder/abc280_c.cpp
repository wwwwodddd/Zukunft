#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
	cin >> s >> t;
	s += "$";
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] != s[i])
		{
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}
