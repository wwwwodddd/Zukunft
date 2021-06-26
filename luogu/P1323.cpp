#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int q[30020], c;
char s[300020];
char t[300020];
int main()
{
	cin >> n >> m;
	q[c++] = 1;
	s[l++] = '1';
	for (int i = 0, j = 0; c < n; c++)
	{
		q[c] = min(q[i] * 2 + 1, q[j] * 4 + 5);
		if (q[i] * 2 + 1 == q[c])
		{
			i++;
		}
		if (q[j] * 4 + 5 == q[c])
		{
			j++;
		}
		l += sprintf(s + l, "%d", q[c]);
	}
	cout << s << endl;
	n = 0;
	for (int i = 0; i < l; i++)
	{
		while (m > 0 && n > 0 && t[n - 1] < s[i])
		{
			m--;
			n--;
		}
		t[n++] = s[i];
	}
	n -= m;
	t[n] = 0;
	cout << t << endl;
	return 0;
}