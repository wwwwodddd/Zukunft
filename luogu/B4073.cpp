#include <bits/stdc++.h>
using namespace std;
int w, n;
int a[] = {0, 4, 6, 9, 10, 17};
int main()
{
	cin >> w >> n;
	if (w <= 500)
	{
		cout << 200 << endl;
	}
	else
	{
		cout << (w - 1) / 500 * a[n] + 20 << endl;
	}
	return 0;
}