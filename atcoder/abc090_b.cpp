#include <bits/stdc++.h>
using namespace std;
int a, b, z;
int rev(int x)
{
	int y = 0;
	while (x > 0)
	{
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}
int main()
{
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		if (rev(i) == i)
		{
			z++; 
		}
	}
	cout << z << endl;
	return 0;
}
