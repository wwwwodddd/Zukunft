#include <bits/stdc++.h>
using namespace std;
string s;
int z;
int main()
{
	cin >> s;
	for (int i = 0, j; i < 10000; i++)
	{
		int v[10] = {};
		v[i % 10] = v[i / 10 % 10] = v[i / 100 % 10] = v[i / 1000] = 1;
		for (j = 0; j < 10; j++)
		{
			if (s[j] == 'x' && v[j] || s[j] == 'o' && !v[j])
			{
				break;
			}
		}
		z += j == 10;
	}
	cout << z << endl;
	return 0;
}
