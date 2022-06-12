#include <bits/stdc++.h>
using namespace std;
int r, c, a, b;
int main()
{
	cin >> r >> c >> a >> b;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < a; j++)
		{
			string s;
			for (int k = 0; k < c; k++)
			{
				for (int l = 0; l < b; l++)
				{
					s += (i + k) & 1 ? '.' : 'X';
				}
			}
			cout << s << endl;
		}
	}
	return 0;
}
