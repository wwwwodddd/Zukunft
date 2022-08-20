#include <bits/stdc++.h>
using namespace std;
int r, c;
int main()
{
	cin >> r >> c;
	if (r > 8)
	{
		r = 16 - r;
	}
	if (c > 8)
	{
		c = 16 - c;
	}
	cout << (min(r, c) & 1 ? "black" : "white") << endl;
	return 0;
}
