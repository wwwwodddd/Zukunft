#include <bits/stdc++.h>
using namespace std;
int a[256];
string s;
int main()
{
	cin >> s;
	for (char c: s)
	{
		a[c]++;
	}
	for (int i: a)
	{
		if (i & 1)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
