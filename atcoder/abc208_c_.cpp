#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[200020];
int b[200020];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		cout << k / n + (b[i] < a[k % n]) << endl;
	}
	return 0;
}
