#include <bits/stdc++.h>
using namespace std;
int n, a[200000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int p1 = max_element(a, a + n) - a;
	int x1 = a[p1];
	a[p1] = 0;
	int x2 = *max_element(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (i == p1)
		{
			cout << x2 << endl;
		}
		else
		{
			cout << x1 << endl;
		}
	}
	return 0;
}
