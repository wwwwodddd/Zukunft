#include <bits/stdc++.h>
using namespace std;
int n;
int c[100020];
void change(int x, int y)
{
	for (x++; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (x++; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
long long z[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		z[x+1] += i - query(x);
		change(x, 1);
	}
	for (int i = 0; i < n; i++)
	{
		z[i + 1] += z[i];
		printf("%lld\n", z[i]);
	}
	return 0;
}