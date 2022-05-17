#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	if (a + b == 15)
	{
		cout << "+" << endl;
	}
	else if (a * b == 15)
	{
		cout << "*" << endl;
	}
	else
	{
		cout << "x" << endl;
	}
	return 0;
}
