#include <bits/stdc++.h>
using namespace std;
string s;
size_t c;
int main()
{
	cin >> s;
	for (char i: s)
	{
		if (i == '0')
		{
			c++;
		}
	}
	cout << min(c, s.size() - c) * 2 << endl;
	return 0;
}
