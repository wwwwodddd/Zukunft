#include <bits/stdc++.h>
using namespace std;
string s;
int c;
int main()
{
	cin >> s;
	for (int i = 0; i + 3 < s.size(); i++)
	{
		if (s.substr(i, 4) == "ZONe")
		{
			c++;
		}
	}
	cout << c << endl;
	return 0;
}
