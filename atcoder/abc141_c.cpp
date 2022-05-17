#include <bits/stdc++.h>
using namespace std;
int n, k, q, x;
int a[100020];
int main()
{
	cin >> n >> k >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << (k - (q - a[i]) > 0 ? "Yes" : "No") << endl;
	}
	return 0;
}
