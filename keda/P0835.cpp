#include <bits/stdc++.h>
using namespace std;
int n, s, a, b;
int x, y[5020], z;
int main()
{
	cin >> n >> s >> a >> b;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y[i];
		if (x > a + b)
		{
			i--;
			n--;
		}
	}
	sort(y, y + n);
	for (int i = 0; i < n; i++)
	{
		if (s >= y[i])
		{
			s -= y[i];
			z++;
		}
	}
	cout << z << endl;
	return 0;
}