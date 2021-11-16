#include <bits/stdc++.h>
using namespace std;
string s, x, y;
int main()
{
	cin >> s;
	x = y = s;
	for (int i = 0; i < s.size(); i++)
	{
		x = min(x, s);
		y = max(y, s);
		s = s.substr(1) + s.substr(0, 1);
	}
	cout << x << endl << y << endl;
	return 0;
}
