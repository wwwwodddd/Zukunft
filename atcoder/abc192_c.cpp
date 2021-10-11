#include <bits/stdc++.h>
using namespace std;
int n, k;
int g1(int x)
{
	int a[20], c = 0;
	while (x > 0)
	{
		a[c++] = x % 10;
		x /= 10;
	}
	sort(a, a + c);
	for (int i = c - 1; i >= 0; i--)
	{
		x = x * 10 + a[i];
	}
	return x;
}
int g2(int x)
{
	int a[20], c = 0;
	while (x > 0)
	{
		a[c++] = x % 10;
		x /= 10;
	}
	sort(a, a + c, greater<int>());
	for (int i = c - 1; i >= 0; i--)
	{
		x = x * 10 + a[i];
	}
	return x;
}
int f(int x)
{
	return g1(x) - g2(x);
}
int main()
{
//	cout << g1(314) << endl;
//	cout << g2(3021) << endl;
//	cout << f(271) << endl;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		n = f(n);
	}
	cout << n << endl;
}
