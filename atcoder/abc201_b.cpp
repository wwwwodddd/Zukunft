#include <bits/stdc++.h>
using namespace std;
int n, h, h1, h2;
string s, s1, s2;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> h;
		if (h1 < h)
		{
			h2 = h1;
			s2 = s1;
			h1 = h;
			s1 = s;
		}
		else if (h2 < h)
		{
			h2 = h;
			s2 = s;
		}
	}
	cout << s2 << endl;
	return 0;
}
