#include <bits/stdc++.h>
using namespace std;
int n, a[9], x, y;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (prev_permutation(a, a + n))
	{
		x++;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	while (prev_permutation(a, a + n))
	{
		y++;
	}
	cout << abs(x - y) << endl;
	return 0;
}
