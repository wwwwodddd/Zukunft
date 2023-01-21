#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[253];
char z[253];
int n, s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		z[i] = '0';
		cout << "? " << i + 1 << " ";
		for (int j = 0; j < n; j++)
		{
			cout << (i != j);
		}
		cout << endl;
		fflush(stdout);
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n, greater<>());
	for (int i = 0; i < n; i++)
	{
		z[a[i].second] = '1';
		s += a[i].first;
		if (s == i * (i + 1) / 2 + (i + 1) * (n - i - 1))
		{
			break;
		}
	}
	cout << "! " << z << endl;
	return 0;
}