#include <bits/stdc++.h>
using namespace std;
int n, x, l, z;
int main()
{
	cin >> n >> l;
	z = l;
	for (int i = 2; i < n; i++)
	{
		cin >> x;
		z += min(l, x);
		l = x;
	}
	z += l;
	cout << z << endl;
	return 0;
}
