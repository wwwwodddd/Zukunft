#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (n % 4 == 0)
		{
			cout << "Even" << endl;
		}
		else if (n % 4 == 2)
		{
			cout << "Same" << endl;
		}
		else
		{
			cout << "Odd" << endl;
		}
	}
}
