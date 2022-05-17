#include <bits/stdc++.h>
using namespace std;
char a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
//	cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	if (a == b && c == d ||
	    a == c && b == d ||
		a == d && b == c)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
