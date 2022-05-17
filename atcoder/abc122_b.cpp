#include <bits/stdc++.h>
using namespace std;
string s;
int z, x;
int main()
{
	cin >> s;
	for (char c: s)
	{
		if (c == 'A' || c == 'C' || c == 'G' || c == 'T')
		{
			z = max(z, ++x);
		}
		else
		{
			x = 0;
		}
	}
	cout << z << endl;
	return 0;
}
