#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int z = n + a[n - 1] * 10;
	n = unique(a, a + n) - a;
	z += n * 5;
	cout << z << endl;
	return 0;
}