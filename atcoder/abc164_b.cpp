#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main()
{
	cin >> a >> b >> c >> d;
	if ((a + d - 1) / d < (c + b - 1) / b)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}
	return 0;
}
