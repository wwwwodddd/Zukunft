#include <bits/stdc++.h>
using namespace std;
int a[9], s;
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (a[i] + a[j] + 100 == s)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k != i && k != j)
					{
						cout << a[k] << endl;
					}
				}
				return 0;
			}
		}
	}
}