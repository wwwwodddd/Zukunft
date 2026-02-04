#include <bits/stdc++.h>
using namespace std;
string s, a, b;
int main()
{
	cin >> s;
	for (auto c : s)
	{
		if (islower(c))
		{
			a += c;
		}
		else
		{
			b += c;
		}
	}
	cout << a << endl;
	cout << b << endl;
	return 0;
}