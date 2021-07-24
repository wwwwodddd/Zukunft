#include <bits/stdc++.h>
using namespace std;
int n, x, v[1020], z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z += v[x]++;
	}
	cout << (z ? "No" : "Yes") << endl;
	return 0;
}
