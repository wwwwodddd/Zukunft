#include <bits/stdc++.h>
using namespace std;
long long a, b, k;
int main()
{
	cin >> a >> b >> k;
	if (k < a)
	{
		cout << a - k << " " << b << endl;
	}
	else if (k < a + b)
	{
		cout << "0 " << a + b - k << endl;
	}
	else
	{
		cout << "0 0" << endl;
	}
	return 0;
}
