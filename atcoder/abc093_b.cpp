#include <bits/stdc++.h>
using namespace std;
int a, b, k;
int main()
{
	cin >> a >> b >> k;
	for (int i = a; i < a + k && i <= b; i++)
	{
		cout << i << endl;
	}
	for (int i = max(b - k + 1, a + k); i <= b; i++)
	{
		cout << i << endl;
	}
	return 0;
}
