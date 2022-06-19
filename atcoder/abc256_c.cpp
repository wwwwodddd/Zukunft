#include <bits/stdc++.h>
using namespace std;
int h1, h2, h3, w1, w2, w3, z;
int main()
{
	cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
	for (int a11 = 1; a11 < h1; a11++)
	{
		for (int a12 = 1; a11 + a12 < h1; a12++)
		{
			int a13 = h1 - a11 - a12;
			for (int a21 = 1; a21 < h2; a21++)
			{
				for (int a22 = 1; a21 + a22 < h2; a22++)
				{
					int a23 = h2 - a21 - a22;
					int a31 = w1 - a11 - a21;
					int a32 = w2 - a12 - a22;
					int a33 = h3 - a31 - a32;
					int A33 = w3 - a13 - a23;
					if (a31 >= 1 && a32 >= 1 && a33 >= 1 && a33 == A33)
					{
						z++;
					}
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
