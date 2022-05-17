#include <bits/stdc++.h>
using namespace std;
int n, x, a, b, f, g, h;
int main()
{
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x <= a)
		{
			f++;
		}
		else if (x <= b)
		{
			g++;
		}
		else
		{
			h++;
		}
	}
	cout << min(min(f, g), h) << endl;
	return 0;
}
