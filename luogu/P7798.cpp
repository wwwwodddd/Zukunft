#include <bits/stdc++.h>
using namespace std;
int n, c, z;
int w[1020];
int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	for (int i = 0; i < n; i++)
	{
		int s = 0, t = 0;
		for (int j = i; j < n; j++)
		{
			if (s + w[j] <= c)
			{
				s += w[j];
				t++;
			}
		}
		z = max(z, t);
	}
	cout << z << endl;
	return 0;
}
