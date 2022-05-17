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
	cout << a + n - unique(a, a + n) << endl;
	return 0;
}
