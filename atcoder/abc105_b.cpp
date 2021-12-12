#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	for (int i = 0; i * 7 <= n && i < 4; i++)
	{
		if ((n - i * 7) % 4 == 0)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
