#include <bits/stdc++.h>
using namespace std;
long long a = 100, x, z;
int main()
{
	for (cin >> x; a < x; a += a / 100)
	{
		z++;
	}
	cout << z << endl;
}
