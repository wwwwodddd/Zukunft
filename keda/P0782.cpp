#include <bits/stdc++.h>
using namespace std;
int n, m, z = -2e9;
int s[500020];
int q[500020], b, f;
int main()
{
	cin >> n >> m;
	q[f++] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
		while (b < f && q[b] < i - m)
		{
			b++;
		}
		z = max(z, s[i] - s[q[b]]);
		while (b < f && s[q[f - 1]] > s[i])
		{
			f--;
		}
		q[f++] = i;
	}
	cout << z << endl;
	return 0;
}