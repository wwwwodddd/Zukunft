#include <bits/stdc++.h>
using namespace std;
string s;
int n, z;
int main()
{
	cin >> n >> s;
	for (char c: s)
	{
		if (c == 'R')
		{
			z++;
		}
		else
		{
			z--;
		}
	}
	cout << (z > 0 ? "Yes" : "No") << endl;
	return 0;
}
