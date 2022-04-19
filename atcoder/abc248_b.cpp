#include <bits/stdc++.h>
using namespace std;
long a, b, k, z;
int main()
{
	cin >> a >> b >> k;
	while (a < b)
	{
		a *= k;
		z++;
	}
	cout << z << endl;
	return 0;
}
