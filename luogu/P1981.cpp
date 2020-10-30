#include <bits/stdc++.h>
using namespace std;
int s, t, x, p = 10000;
char c;
int main()
{
	cin >> x;
	do
	{
		if (c == '*')
		{
			t = x % p * t % p;
		}
		else
		{
			s = (s + t) % p;
			t = x % p;
		}
	}
	while (cin >> c >> x);
	cout << (s + t) % p << endl;
	return 0;
}