#include <bits/stdc++.h>
using namespace std;
int y;
int main()
{
	cin >> y;
	if (y % 172800 == 0)
	{
		cout << "Yes" << endl;
	}
	else if (y % 3200 == 0)
	{
		cout << "No" << endl;
	}
	else if (y % 400 == 0)
	{
		cout << "Yes" << endl;
	}
	else if (y % 100 == 0)
	{
		cout << "No" << endl;
	}
	else if (y % 4 == 0)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}