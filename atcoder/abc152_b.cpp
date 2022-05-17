#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	if (a > b)
	{
		swap(a, b);
	}
	for (int i = 0; i < b; i++)
	{
		cout << a;
	}
	return 0;
}
