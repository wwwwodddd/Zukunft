#include <bits/stdc++.h>
using namespace std;
int n, f;
char c;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'Y')
		{
			f = 1;
		}
	}
	cout << (f ? "Four" : "Three") << endl;
	return 0;
}
