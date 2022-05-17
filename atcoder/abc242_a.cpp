#include <bits/stdc++.h>
using namespace std;
int a, b, c, x;
int main()
{
	cin >> a >> b >> c >> x;
	if (x <= a)
	{
		cout << 1 << endl;
	}
	else if (x <= b)
	{
		cout << (double)c / (b - a) << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
