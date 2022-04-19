#include <bits/stdc++.h>
using namespace std;
int n;
int a[300020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << (a[n - 1] - a[n - 2] == 1 && (a[n - 1] - n - 1) % 2 == 0 ? "Bob" : "Alice") << endl;
	return 0;
}
