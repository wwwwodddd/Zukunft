#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = (s.size() - 1) / 2; i > 0; i--)
	{
		if (s.substr(0, i) == s.substr(i, i))
		{
			cout << 2 * i << endl;
			break;
		}
	}
	return 0;
}
