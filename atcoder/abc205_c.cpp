#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
	cin >> a >> b >> c;
	if (c % 2 == 0)
	{
		a = abs(a);
		b = abs(b);
	}
	cout << (a < b ? '<' : a > b ? '>' : '=') << endl;
	return 0;
}
