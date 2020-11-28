#include <bits/stdc++.h>
using namespace std;
int n, z;
string s;
bool v[2020][2020];
bool r[2020][2020];
bool c[2020][2020];
int main()
{
	cin >> n >> s;
	int x = 1010;
	int y = 1010;
	v[x][y] = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'N')
		{
			if (!c[x][y] && v[x][y + 1])
			{
				z++;
			}
			c[x][y] = true;
			v[x][y + 1] = true;
			y++;
		}
		else if (s[i] == 'S')
		{
			if (!c[x][y - 1] && v[x][y - 1])
			{
				z++;
			}
			c[x][y - 1] = true;
			v[x][y - 1] = true;
			y--;
		}
		else if (s[i] == 'E')
		{
			if (!r[x][y] && v[x + 1][y])
			{
				z++;
			}
			r[x][y] = true;
			v[x + 1][y] = true;
			x++;
		}
		else if (s[i] == 'W')
		{
			if (!r[x - 1][y] && v[x - 1][y])
			{
				z++;
			}
			r[x - 1][y] = true;
			v[x - 1][y] = true;
			x--;
		}
	}
	cout << z << endl;
	return 0;
}