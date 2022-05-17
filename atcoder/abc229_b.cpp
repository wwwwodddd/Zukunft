#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main()
{
	cin >> a >> b;
	while (a > 0 || b > 0)
	{
		if (a % 10 + b % 10 >= 10)
		{
			cout << "Hard" << endl;
			return 0;
		}
		a /= 10;
		b /= 10;
	}
	cout << "Easy" << endl;
	return 0;
}
