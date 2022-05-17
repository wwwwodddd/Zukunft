#include <bits/stdc++.h>
using namespace std;
int a, b, c, k;
int main()
{
	cin >> a >> b >> c >> k;
	if (k <= a)
	{
		cout << k << endl;
	}
	else if (k <= a + b)
	{
		cout << a << endl;
	}
	else
	{
		cout << a - (k - a - b) << endl;
	}
	return 0;
}
