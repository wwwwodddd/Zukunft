#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] + t[0]) % 26 != (t[i] + s[0]) % 26)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
