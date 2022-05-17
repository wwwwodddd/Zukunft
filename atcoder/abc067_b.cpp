#include <bits/stdc++.h>
using namespace std;
int n, k, s, a[50];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = n - k; i < n; i++)
	{
		s += a[i];
	}
	cout << s << endl;
	return 0;
}
