#include <bits/stdc++.h>
using namespace std;
string s[3];
int p[3], c;
int main()
{
	cin >> s[0] >> s[1] >> s[2];
	while (p[c] != s[c].size())
	{
		c = s[c][p[c]++] - 'a';
	}
	cout << char('A' + c) << endl;
	return 0;
}
