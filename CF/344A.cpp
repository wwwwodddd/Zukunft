#include <bits/stdc++.h>
using namespace std;
int n, a[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	n = unique(a, a + n) - a;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	cout << n << endl;
	return 0;
}
// 1 1 1 2 2 2 1 1 1
// 1 2 1
// ^     ^
// a     unique
