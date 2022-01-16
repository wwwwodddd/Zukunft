#include <bits/stdc++.h>
using namespace std;
int n, x;
string s;
int main()
{
	cin >> n >> x >> s;
	for (char c:s)
	{
		if (c == 'x')
		{
			x--;
			if (x < 0)
			{
				x = 0;
			}
		}
		else
		{
			x++;
		}
	}
	cout << x << endl;
	return 0;
}
