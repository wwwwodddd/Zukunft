#include <bits/stdc++.h>
using namespace std;
string s[4];
int z;
int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> s[i];
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j] != '.')
			{
				int x = (s[i][j] - 'A') / 4;
				int y = (s[i][j] - 'A') % 4;
				z += abs(x - i) + abs(y - j);
			}
		}
	}
	cout << z << endl;
	return 0;
}
