#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
int m;
void mul(int a[101][101], int b[101][101])
{
	int w[101][101] = {};
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < m; k++)
			{
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int a[101][101];
int b[101][101];
void F(long long n)
{
	memset(a, 0, sizeof a);
	for (int i = 0; i < m; i++)
	{
		a[i][i] = 1;
	}
	for (; n > 0; n >>= 1)
	{
		if (n & 1)
		{
			mul(a, b);
		}
		mul(b, b);
	}
}
int main()
{
	long long n;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}
	F(n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}