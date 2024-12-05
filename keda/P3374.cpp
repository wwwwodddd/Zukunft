#include <bits/stdc++.h>
using namespace std;
int z, s;
string t;
int main()
{
	cin >> t;
	for (int i : t)
	{
		if (i == '(')
		{
			s++;
		}
		else
		{
			if (s > 0)
			{
				s--;
			}
			else
			{
				s++;
				z++;
			}
		}
	}
	z += s / 2;
	cout << z << endl;
	return 0;
}