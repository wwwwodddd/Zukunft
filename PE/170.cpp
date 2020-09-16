#include <bits/stdc++.h>
using namespace std;
long long a[10];
int cnt = 10000;
void dfs(int r, int d, int x, int y)
{
	// if (--cnt == 0)
	// {
	// 	exit(0);
	// }
	// printf("%d %d %d %d:", r, d, x, y);
	// for (int i = 0; i < d; i++)
	// {
	// 	printf(" %d*%lld=%lld", r, a[i], (long long)r*a[i]);
	// }
	// printf("\n");
	if (x == 1023 && y == 1023)
	{
		if (d == 1)
		{
			return;
		}
		string w[10], ww;
		for (int i = 0; i < d; i++)
		{
			// printf("%d x %lld = %lld\n", r, a[i], r * a[i]);
			stringstream itos;
			itos << r * a[i];
			itos >> w[i];
		}
		sort(w, w + d);
		for (int i = d - 1; i >= 0; i--)
		{
			ww += w[i];
		}
		cout << ww;
		for (int i = 0; i < d; i++)
		{
			printf(" %dx%lld=%lld", r, a[i], r * a[i]);
		}
		printf("\n");
		return;
	}
	int s = 1023 ^ x;
	for (int ss = s; ss > 0; --ss &= s)
	{
		int b[10] = {}, bc = 0;
		if (true)
		{
			int nx = x;
			for (int i = 0; i < 10; i++)
			{
				if (ss >> i & 1)
				{
					b[bc++] = i;
					nx |= 1 << i;
				}
			}
			do
			{
				a[d] = 0;
				if (b[0] == 0)
				{
					continue;
				}
				for (int i = 0; i < bc; i++)
				{
					a[d] = a[d] * 10 + b[i];
				}
				long long t = a[d] * r;
				int ny = y;
				bool bad = false;
				while (t > 0)
				{
					if (ny & 1 << (t % 10))
					{
						bad = true;
						break;
					}
					ny |= 1 << (t % 10);
					t /= 10;
				}
				if (bad)
				{
					continue;
				}
				dfs(r, d + 1, nx, ny);
			}
			while (next_permutation(b, b + bc));
		}
	}
}

int main()
{
	for (int r = 2; r < 1000; r++)
	{
		int x = 0, t = r;
		bool bad = false;
		while (t > 0)
		{
			if (x & 1 << (t % 10))
			{
				bad = true;
				break;
			}
			x |= 1 << (t % 10);
			t /= 10;
		}
		if (bad)
		{
			continue;
		}
		dfs(r, 0, x, 0);
	}
	return 0;
}