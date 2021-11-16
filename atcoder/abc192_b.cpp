#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (i & 1 && islower(s[i]) || ~i & 1 && isupper(s[i]))
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
