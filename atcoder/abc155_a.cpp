#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a == b && b == c)
	{
		cout << "No" << endl;
	}
	else if (a == b || b == c || a == c)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}
