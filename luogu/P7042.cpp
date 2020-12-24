#include <bits/stdc++.h>
using namespace std;
int64_t q, a[4];
int main() {
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		for (int i = 0; i < 4; i++)
		{
			cin >> a[i];
		}
		sort(a, a + 4);
		if (a[0] + a[3] != a[1] + a[2])
		{
			cout << 0 << endl;
		}
		else if (a[0] == a[3])
		{
			cout << 1 << endl;
		}
		else if (a[0] == a[1])
		{
			cout << 4 << endl;
		}
		else
		{
			cout << 8 << endl;
		}
	}
	return 0;
}