#include <bits/stdc++.h>
using namespace std;
int n, q, o, k, x;
int a[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> o >> k;
		if (o == 1)
		{
			cin >> x;
			a[k] = x;
		}
		else
		{
			cout << a[k] << endl;
		}
	}
	return 0;
}
