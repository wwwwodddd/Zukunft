#include <bits/stdc++.h>
using namespace std;
int t;
int a[4], b[4], c[4];
bool win(int a[4], int b[4])
{
	int z = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i] > b[j])
			{
				z++;
			}
			else if (a[i] < b[j])
			{
				z--;
			}
		}
	}
	return z > 0;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		cin >> b[0] >> b[1] >> b[2] >> b[3];
		if (win(b, a))
		{
			swap(a, b);
		}
		int f = 0;
		for (c[0] = 1; c[0] <= 10; c[0]++)
		{
			for (c[1] = 1; c[1] <= 10; c[1]++)
			{
				for (c[2] = 1; c[2] <= 10; c[2]++)
				{
					for (c[3] = 1; c[3] <= 10; c[3]++)
					{
						if (win(b, c) && win(c, a))
						{
							f = 1;
							goto end;
						}
					}
				}
			}
		}
	end:
		cout << (f ? "yes" : "no") << endl;
	}
	return 0;
}