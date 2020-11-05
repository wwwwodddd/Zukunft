#include <bits/stdc++.h>
using namespace std;
int n, z;
string s, t;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s != t)
		{
			z++;
		}
		t = s;
	}
	cout << z + 1 << endl;
	return 0;
}