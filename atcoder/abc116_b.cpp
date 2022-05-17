#include <bits/stdc++.h>
using namespace std;
int s, z;
int main()
{
	cin >> s;
	while (s != 1 && s != 2 && s != 4)
	{
		z++;
		if (s & 1)
		{
			s = s * 3 + 1;
		}
		else
		{
			s = s / 2;
		}
	}
	cout << z + 4 << endl;
	return 0;
}
