#include <bits/stdc++.h>
using namespace std;
int n, m, l, z, t;
string s;
int a[100020], c;
int main()
{
	cin >> n >> m >> s;
	char p = '1';
	for (char i : s)
	{
		if (p == i)
		{
			c++;
		}
		else
		{
			a[l++] = c;
			c = 1;
			p = i;
		}
	}
	a[l++] = c;
	if (l % 2 == 0)
	{
		a[l++] = 0;
	}
	for (int i = 0; i < l; i++)
	{
//		cout << i << " " << a[i] << endl;
		t += a[i];
		if (i % 2 == 0)
		{
			z = max(z, t);		
		}
		if (i >= 2 * m)
		{
			t -= a[i - 2 * m];
		}
	}
	cout << z << endl;
	return 0;
}
