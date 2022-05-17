#include <bits/stdc++.h>
using namespace std;
int n, k, z;
int main()
{
	for (cin >> n >> k; n > 0; n /= k)
	{
		z++;
	}
	cout << z << endl;
	return 0;
}
