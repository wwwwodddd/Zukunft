#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int c[100020];
pair<int, int> a[50020];
void R(int x, int y)
{
	for (; x <= 2 * n; x += x & -x)
	{
		c[x] += y;
	}
}
int G(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= 2 * n; i++)
	{
		cin >> x;
		a[x].first = a[x].second;
		a[x].second = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		z += G(a[i].second) - G(a[i].first);
		R(a[i].second, 1);
	}
	cout << z << endl;
	return 0;
}