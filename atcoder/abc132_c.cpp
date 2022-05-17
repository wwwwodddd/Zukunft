#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[n / 2] - a[n / 2 - 1] << endl;
    return 0;
}
