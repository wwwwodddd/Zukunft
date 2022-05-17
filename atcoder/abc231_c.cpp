#include <bits/stdc++.h>
using namespace std;
int n, q, x;
int a[200020];
int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < q; i++)
	{
		cin >> x;
		cout << a + n - lower_bound(a, a + n, x) << endl; 
	}
}
