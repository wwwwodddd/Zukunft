#include <bits/stdc++.h>
using namespace std;
int t, a1, a2, a3, a4, a5, k;
bool zuo()
{
	scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &k);
	if (k % 10)
	{
		return false;
	}
	int b5 = min(a5, k / 200);
	a5 -= b5;
	k -= b5 * 200;
	int b4 = min(a4, k / 100);
	a4 -= b4;
	k -= b4 * 100;
	if (k >= 200 && a3 >= 2)
	{
		int b3 = min((a3 - 2) / 2, (k - 200) / 100);
		a3 -= b3 * 2;
		k -= b3 * 50;
	}
	if (k >= 200 && a2 >= 5)
	{
		int b2 = min((a2 - 5) / 5, (k - 200) / 100);
		a2 -= b2 * 5;
		k -= b2 * 20;
	}
	for (int i = 0; i <= a3 && i * 50 <= k; i++)
	{
		for (int j = 0; j <= a2 && i * 50 + j * 20 <= k; j++)
		{
			if (k - i * 50 - j * 20 <= a1 * 10)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		puts(zuo() ? "TAK" : "NIE");
	}
	return 0;
}