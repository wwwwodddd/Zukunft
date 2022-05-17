#include <bits/stdc++.h>
using namespace std;
string a, b;
int f;
int main()
{
	cin >> a >> b;
	if (a == b)
	{
		f = 1;
	}
	for (int i = 1; i < a.size(); i++)
	{
		swap(a[i], a[i - 1]);
		if (a == b)
		{
			f = 1;
		}
		swap(a[i], a[i - 1]);
	}
	cout << (f ? "Yes" : "No") << endl;
}
