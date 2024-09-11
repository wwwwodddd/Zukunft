#include <bits/stdc++.h>
using namespace std;
string s[6];
bool ok()
{
	for (int i = 0; i < 3; i++)
	{
		if (string("") + s[3][i] + s[4][i] + s[5][i] != s[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> s[i];
	}
	do
	{
		if (ok())
		{
			cout << s[0] << endl;
			cout << s[1] << endl;
			cout << s[2] << endl;
			return 0;
		}
	}
	while (next_permutation(s, s + 6));
	cout << "0" << endl;
	return 0;
}
