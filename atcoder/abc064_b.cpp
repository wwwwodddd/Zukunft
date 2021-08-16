#include <bits/stdc++.h>
using namespace std;
int n, a[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << *max_element(a, a + n) - *min_element(a, a + n) << endl;
	return 0;
}
