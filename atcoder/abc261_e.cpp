#include <bits/stdc++.h>
using namespace std;
int n, c, t, a;
int z[200020];
int main()
{
	cin >> n >> c;
	int z = 0, o = (1 << 30) - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> a;
		if (t == 1)
		{
			z &= a;
			o &= a;
		}
		else if (t == 2)
		{
			z |= a;
			o |= a;
		}
		else
		{
			z ^= a;
			o ^= a;
		}
		c = ~c & z | c & o;
		cout << c << endl;
	}
	return 0;
}
