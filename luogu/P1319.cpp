#include <bits/stdc++.h>
using namespace std;
int n, x;
int main()
{
	cin >> n;
	for (int i = 0, c = '0'; cin >> x; c ^= 1)
	{
		while (x--)
		{
			putchar(c);
			if (++i % n == 0)
			{
				putchar(10);
			}
		}
	}
	return 0;
}