#include <bits/stdc++.h>
using namespace std;
int r, d, x;
int main()
{
	cin >> r >> d >> x;
	for (int i = 0; i < 10; i++)
	{
		x = r * x - d;
		cout << x << endl;
	}
	return 0;
}
