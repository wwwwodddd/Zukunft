#include <bits/stdc++.h>
using namespace std;
int l, d, x;
int F(int x)
{
	return x < 10 ? x : F(x / 10) + x % 10;
}
int main()
{
	cin >> l >> d >> x;
	while (F(l) != x)
	{
		l++;
	}
	while (F(d) != x)
	{
		d--;
	}
	cout << l << endl << d << endl;
	return 0;
}