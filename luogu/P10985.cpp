#include <bits/stdc++.h>
using namespace std;
int n, z;
int main()
{
	cin >> n;
	while (n > 0)
	{
		int m = n;
		while (m > 0)
		{
			n -= m % 10;
			m /= 10;
		}
		z++;
	}
	cout << z << endl;
	return 0;
}