#include <bits/stdc++.h>
using namespace std;
int n, f, g, p, q, x;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			f++;
			g = max(g - 1, 0);
		}
		else
		{
			g++;
			f = max(f - 1, 0);
		}
		p = max(p, f);
		q = max(q, g);
	}
	cout << p + q + 1 << endl;
	return 0;
}
