#include <bits/stdc++.h>
using namespace std;
int a, b, c, d[99];
int F(int a, int b, int c)
{
	memset(d, 0, sizeof d);
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			for (int k = 1; k <= c; k++)
			{
				d[i + j + k]++;
			}
		}
	}
	return max_element(d, d + 99) - d;
}
int G(int a, int b, int c)
{
	a = min(a, b + c);
	b = min(b, a + c);
	c = min(c, a + b);
	return (a + b + c + 3) / 2;
}
int main()
{
	cin >> a >> b >> c;
	cout << G(a, b, c) << endl;
	return 0;
}