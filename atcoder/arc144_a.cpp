#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	cout << 2 * n << endl;
	cout << (n - 1) % 4 + 1;
	for (int i = 0; i < (n - 1) / 4; i++)
	{
		cout << 4;
	}
	cout << endl;
	return 0;
}
