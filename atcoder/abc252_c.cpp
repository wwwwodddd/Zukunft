#include <bits/stdc++.h>
using namespace std;
int n;
int a[10], r[10][10];
string s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < 10; j++)
		{
			int d = s[j] - '0';
			a[d] = max(a[d], j + r[d][j]++ * 10);
		}
	}
	cout << *min_element(a, a + 10) << endl;
	return 0;
}
