#include <bits/stdc++.h>
using namespace std;
int x, y;
int main()
{
	cin >> x >> y;
	for (int i = max(x, y); i <= 6; i++)
	{
		cout << i << ' ';
	}
	return 0;
}