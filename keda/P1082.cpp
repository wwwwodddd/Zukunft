#include <bits/stdc++.h>
using namespace std;
void exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	else
	{
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
}
int main()
{
	int a, b, x, y;
	cin >> a >> b;
	exgcd(a, b, x, y);
	if (x < 0)
	{
		x += b;
		y -= a;
	}
	cout << x << endl;
}