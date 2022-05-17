#include <bits/stdc++.h>
using namespace std;
int n, l;
string s;
int main()
{
	cin >> n >> s;
	l = n / 2;
	if (n % 2 == 0)
	{
		l = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] != 'a' + (n + i) % 3)
		{
			l = -1;
		}
	}
	cout << l << endl;
	return 0;
}
