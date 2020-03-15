#include <bits/stdc++.h>
using namespace std;
int n, ss1, ss2;
long long a[42], m, z;
long long s1[1048577];
long long s2[1048577];
void gao(long long *a, int n, long long *s, int &ss)
{
	for (int i = 0; i < n; i++)
	{
		s[1 << i] = a[i];
	}
	for (int i = 1; i < 1 << n; i++)
	{
		s[i] = s[i - (i & -i)] + s[i & -i];
	}
	ss = 1 << n;
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
	for (int i = 0, j = ss2; i < ss1; i++)
	{
		while (j > 0 && s1[i] + s2[j - 1] > m)
		{
			j--;
		}
		z += j;
	}
	cout << z << endl;
	return 0;
}