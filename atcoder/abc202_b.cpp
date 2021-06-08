#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	reverse(s.begin(), s.end());
	for (char &i: s)
	{
		if (i == '6' || i == '9')
		{
			i ^= 15;
		}
	}
	cout << s << endl;
	return 0;
}
