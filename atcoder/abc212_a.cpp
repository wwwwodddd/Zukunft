#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	if (b == 0)
	{
		cout << "Gold" << endl;
	}
	else if (a == 0)
	{
		cout << "Silver" << endl;
	}
	else
	{
		cout << "Alloy" << endl;
	}
	return 0;
}
