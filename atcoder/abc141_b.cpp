#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (i % 2 == 0 && s[i] == 'L' || i % 2 == 1 && s[i] == 'R')
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
