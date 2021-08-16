#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	if (n < 126)
	{
		cout << 4 << endl;
	}
	else if (n < 212)
	{
		cout << 6 << endl;
	}
	else
	{
		cout << 8 << endl;
	}
	return 0;
}
