#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
int b[100020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (j < m && b[j] == a[i])
		{
			j++;
		}
	}
	cout << (j < m ? "No" : "Yes") << endl;
	return 0;
}
