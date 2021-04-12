#include <bits/stdc++.h>
using namespace std;
char s[7][7];
int h, w, k, z = 0;
int main()
{
	cin >> h >> w >> k;
	for (int i = 0; i < h; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < 1 << h; i++)
	{
		for (int j = 0; j < 1 << w; j++)
		{
			int c = 0;
			for (int k = 0; k < h; k++)
			{
				for (int l = 0; l < w; l++)
				{
					c += i >> k & 1 && j >> l & 1 && s[k][l] == '#';
				}
			}
			z += c == k;
		}
	}
	cout << z << endl;
	return 0;
}