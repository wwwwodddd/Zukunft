#include <bits/stdc++.h>
using namespace std;
long long n;
long long t[20];
long long G(long long n)
{
	n++;
	int a[20], c = 0;
	while (n > 0)
	{
		a[c++] = n % 10;
		n /= 10;
	}
	long long re = 0;
	for (int i = 1; i < c; i++)
	{
		for (int j = 1; j < i; j++)
		{
			re += j * 9 * t[i - j - 1];
		}
		re += i; // i == j;
	}
	for (int i = c - 1; i >= 0; i--)
	{
		if (a[i] > 1)
		{
			for (int j = 1; j <= i; j++)
			{
				re += (c - j) * 9 * t[j - 1];
			}
			re += c;
			int s = 0;
			for (int j = i; j >= 0; j--)
			{
				s = s * 10 + a[j];
			}
			re += (c - i - 1) * (s - t[i]);
			break;
		}
		else if (a[i] < 1)
		{
			int s = 0;
			for (int j = i; j >= 0; j--)
			{
				s = s * 10 + a[j];
			}
			re += (c - i - 1) * s;
			break;
		}
		else
		{
			re += (c - i - 1) * t[i];
		}
	}
	return re;
}
long long FF(long long n)
{
	int a[20], c = 0;
	while (n > 0)
	{
		a[c++] = n % 10;
		n /= 10;
	}
	int re = 0;
	while (c >= 0 && a[c - 1] == 1)
	{
		re++;
		c--;
	}
	return re;
}
long long F(long long n)
{
	int re = 0;
	for (int i = 1; i <= n; i++)
	{
		re += FF(i);
	}
	return re;
}
int main()
{
	for (int i = t[0] = 1; i < 19; i++)
	{
		t[i] = t[i - 1] * 10;
	}
	cin >> n;
	cout << G(n) << endl;
	return 0;
}
