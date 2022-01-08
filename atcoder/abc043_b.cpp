#include <bits/stdc++.h>
using namespace std;
string s, z;
int main()
{
	cin >> s;
	for (char c: s)
	{
		if (c == 'B')
		{
			if (z.size() > 0)
			{
				z.pop_back();
			}
		}
		else
		{
			z += c;
		}
	}
	cout << z << endl;
	return 0;
}
