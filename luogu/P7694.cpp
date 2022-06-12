#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0 || s[i - 1] == '-')
		{
			cout << s[i];
		}
	}
	return 0;
}
