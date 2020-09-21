#include <bits/stdc++.h>
using namespace std;
double m, h;
int main()
{
	cin >> m >> h;
	if (m < 18.5 * h * h)
	{
		cout << "Underweight" << endl;
	}
	else if (m < 24 * h * h)
	{
		cout << "Normal" << endl;
	}
	else
	{
		cout << m / h / h << endl << "Overweight" << endl;
	}
	return 0;
}