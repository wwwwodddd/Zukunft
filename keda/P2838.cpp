#include <bits/stdc++.h>
using namespace std;
int n, x;
int c[2];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x % 2]++;
	}
	int z = 0;
	while (true)
	{
		if (z % 2 == 0)
		{
			if (c[0] >= 1)
			{
				c[0]--;
				z++;
			}
			else if (c[1] >= 2)
			{
				c[1] -= 2;
				z++;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (c[1] >= 1)
			{
				c[1]--;
				z++;
			}
			else
			{
				break;
			}
		}
	}
	if (c[1] > 0)
	{
		z--;
	}
	cout << z << endl;
	return 0;
}