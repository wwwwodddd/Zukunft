#include <bits/stdc++.h>
using namespace std;
int n, x, l, z = 1, d; 
int main()
{
	cin >> n >> l;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		if (d == 0 || d == 1 && l <= x || d == -1 && l >= x)
		{			
			if (l < x)
			{
				d = 1;
			}
			else if (l > x)
			{
				d = -1;
			}
		}
		else
		{
			z++;
			d = 0;			
		}
		l = x;
	}
	cout << z << endl; 
	return 0;
}
