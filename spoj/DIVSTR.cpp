#include <bits/stdc++.h>
using namespace std;
int cases;
string s, t;
int main()
{
	cin >> cases;
	getline(cin, s);
	for (int tt = 0; tt < cases; tt++)
	{
		getline(cin, s);
		getline(cin, t);
		int j = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == t[j % t.size()])
			{
				j++;
			}
		}
		cout << s.size() - j / t.size() * t.size() << endl;
	}
	return 0;
}