#include <bits/stdc++.h>
using namespace std;
int a[10];
int fac[10];
int d[362881];
void decode(int x)
{
	int v[10] = {};
	for (int i = 0; i < 9; i++)
	{
		int cnt = x % fac[9 - i] / fac[8 - i];
		for (int j = 0; j < 9; j++)
		{
			if (v[j] == 0)
			{
				if (cnt == 0)
				{
					a[i] = j;
					v[j] = 1;
					break;
				}
				else
				{
					cnt--;
				}
			}
		}
	}
}
int encode()
{
	int v[10] = {};
	int re = 0;
	for (int i = 0; i < 9; i++)
	{
		int cnt = 0;
		for (int j = 0; j < a[i]; j++)
		{
			if (v[j] == 0)
			{
				cnt++;
			}
		}
		v[a[i]] = 1;
		re += cnt * fac[8 - i];
	}
	return re;
}
int main()
{
	fac[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		fac[i] = fac[i - 1] * i;
	}
	for (int i = 0; i < fac[9]; i++)
	{
		d[i] = -1;
	}
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size())
	{
		int u = q.front();
		q.pop();
		decode(u);
		for (int i = 0; i < 6; i++)
		{
			swap(a[i], a[i + 3]);
			int w = encode();
			if (d[w] == -1)
			{
				d[w] = d[u] + 1;
				q.push(w);
			}
			swap(a[i], a[i + 3]);
		}
		for (int i = 0; i < 9; i++)
		{
			if (i % 3 == 2)
			{
				continue;
			}
			swap(a[i], a[i + 1]);
			int w = encode();
			if (d[w] == -1)
			{
				d[w] = d[u] + 1;
				q.push(w);
			}
			swap(a[i], a[i + 1]);
		}
	}
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	printf("%d\n", d[encode()]);
	return 0;
}