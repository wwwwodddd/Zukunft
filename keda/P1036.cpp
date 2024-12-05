#include <bits/stdc++.h>
using namespace std;
long long a, b, r = 1;
int main()
{
	cin >> a >> b;
	if (a == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		for (int i = 0; i < b; i++)
		{
			r *= a;
			if (r > 1e9)
			{
				r = -1;
				break;
			}
		}
		cout << r << endl;
	}
	return 0;
}