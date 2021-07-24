#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		cout << s[0];
		for (int i = 1; i < s.size(); i += 2)
		{
			cout << s[i];
		}
		cout << endl;
	}
}
