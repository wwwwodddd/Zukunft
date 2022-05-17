#include <bits/stdc++.h>
using namespace std;
string s, t;
int main()
{
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++)
	{
		if (s.substr(i) + s.substr(0, i) == t)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
