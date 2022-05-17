#include <bits/stdc++.h>
using namespace std;
int d, n;
int main()
{
	cin >> d >> n;
	n += n / 100;
	while (d--)
	{
		n *= 100;
	}
	cout << n << endl;
	return 0;
}
