#include <bits/stdc++.h>
using namespace std;
int h, w, n, ac, bc;
int a[100020];
int aa[100020];
int b[100020];
int bb[100020];
int main()
{
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		aa[i] = a[i];
		bb[i] = b[i];
	}
	sort(aa, aa + n);
	sort(bb, bb + n);
	ac = unique(aa, aa + n) - aa;
	bc = unique(bb, bb + n) - bb;
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(aa, aa + ac, a[i]) - aa;
		b[i] = lower_bound(bb, bb + bc, b[i]) - bb;
		cout << a[i] + 1 << ' ' << b[i] + 1 << endl;
	}
	return 0;
}