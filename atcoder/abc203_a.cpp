#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (a == b || b == c || a == c)
	{
		cout << (a ^ b ^ c) << endl;
	}
	else
	{
		cout << 0 << endl;
	}
	return 0;
}
