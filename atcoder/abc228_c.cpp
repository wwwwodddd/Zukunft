#include <bits/stdc++.h>
using namespace std;
int n, k, x, y, z;
int a[100020];
int b[100020];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> z;
		b[i] = a[i] = x + y + z;
	}
	sort(a, a + n, greater<>());
	for (int i = 0; i < n; i++)
	{
		cout << (b[i] + 300 >= a[k - 1] ? "Yes" : "No") << endl;
	}
	return 0;
}
