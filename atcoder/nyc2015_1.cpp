#include <bits/stdc++.h>
using namespace std;
int F(int x)
{
	int r = 0;
	for (; x > 0; x /= 2)
	{
		r = r * 2 + x % 2;
	}
	return r;
}
int main()
{
	int x;
	cin >> x;
	cout << (F(x) == x ? "Yes" : "No") << endl;
	return 0;
}