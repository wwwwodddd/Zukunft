#include <bits/stdc++.h>
using namespace std;
int a[8];
int main()
{
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}
	if (is_sorted(a, a + 8))
	{
		cout << "ascending" << endl;
	}
	else if (is_sorted(a, a + 8, greater<int>()))
	{
		cout << "descending" << endl;
	}
	else
	{
		cout << "mixed" << endl;
	}
	return 0;
}
