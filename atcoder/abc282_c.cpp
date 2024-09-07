#include <bits/stdc++.h>
using namespace std;
int n, c;
string s;
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '"')
		{
			c ^= 1;
		}
		if (c == 0 && s[i] == ',')
		{
			s[i] = '.';
		}
	}
	cout << s << endl;
	return 0;
}
