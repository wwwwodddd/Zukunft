#include <bits/stdc++.h>
using namespace std;
string s;
int c;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		c++;
		if (i + 1 == s.size() || s[i] != s[i + 1])
		{
			cout << s[i] << c;
			c = 0;
		}
	}
	cout << endl;
}
