#include <bits/stdc++.h>
using namespace std;
string s;
int v[256];
int main()
{
	cin >> s;
	for (char c: s)
	{
		v[c] = 1;
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		if (!v[c])
		{
			cout << c << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;
}
