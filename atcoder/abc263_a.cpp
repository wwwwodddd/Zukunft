#include <bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	sort(a, a + 5);
	if (a[0] == a[2] && a[3] == a[4] || a[0] == a[1] && a[2] == a[4])
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;		
	}
	return 0;
}
