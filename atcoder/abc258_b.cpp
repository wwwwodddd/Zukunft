#include <bits/stdc++.h>
using namespace std;
int n;
string s[10], z;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				string t;
				for (int l = 0; l < n; l++)
				{
					t += s[(i + dx[k] * l + n) % n][(j + dy[k] * l + n) % n];
				}
				z = max(z, t);
			}
		}
	}
	cout << z << endl;
	return 0;
}
