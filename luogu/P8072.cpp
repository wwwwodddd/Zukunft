#include <bits/stdc++.h>
using namespace std;
int k, z = 1, y = 0;
int main()
{
	cin >> k;
	while (z < k)
	{
		z *= 2;
	}
	while (k % (z >> y))
	{
		y++;
	}
	cout << z << " " << y << endl;
	return 0;
}
