#include <bits/stdc++.h>
using namespace std;
int n, l, r, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		z += r - l + 1;
	}
	cout << z << endl;
	return 0;
}
