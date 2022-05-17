#include <bits/stdc++.h>
using namespace std;
int n, m, x, z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z += min(x, m - x);
	}
	cout << 2 * z << endl;
	return 0;
}
