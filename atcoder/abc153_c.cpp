#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200000];
long long s;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n - k; i++)
	{
		s += a[i];
	}
	cout << s << endl;
    return 0;
}
