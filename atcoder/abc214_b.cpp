#include <bits/stdc++.h>
using namespace std;
int s, t, z;
int main()
{
	cin >> s >> t;
	for (int a = 0; a <= s; a++)
	{
		for (int b = 0; a + b <= s; b++)
		{
			for (int c = 0; a + b + c <= s && a * b * c <= t; c++)
			{
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}
