#include <bits/stdc++.h>
using namespace std;
char s[60][60];
int r, c, zr, zc;
int main()
{
	cin >> r >> c >> zr >> zc;
	for (int i = 0; i < r; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < r * zr; i++)
	{
		for (int j = 0; j < c * zc; j++)
		{
			cout << s[i / zr][j / zc];
		}
		cout << endl;
	}
	return 0;
}