#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[41];
int s1[1048577], ss1;
int s2[1048577], ss2;
void gao(int *a, int n, int *s, int &ss)
{
	ss = 0;
	for (int i = 0; i < 1 << n; i++)
	{
		int u = 0;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				u += a[j];
				if (u > m)
				{
					break;
				}
			}
		}
		if (u <= m)
		{
			s[ss++] = u;
		}
	}
	sort(s, s + ss);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	random_shuffle(a, a + n);
	gao(a, n / 2, s1, ss1);
	gao(a + n / 2, n - n / 2, s2, ss2);
	long long z = 0;
	for (int i = ss1 - 1, j = 0, k = 0; i >= 0; i--)
	{
		while (j < ss2 && m - s1[i] > s2[j])
		{
			j++;
		}
		while (k < ss2 && m - s1[i] >= s2[k])
		{
			k++;
		}
		z += k - j;
	}
	cout << z << endl;
	return 0;
}