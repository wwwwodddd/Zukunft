#include <bits/stdc++.h>
using namespace std;
int n, a[10];
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	do
	{
		for (int i = 0; i < n; i++)
		{
			cout << setw(5) << a[i];
		}
		cout << endl;
	}
	while (next_permutation(a, a + n));
	return 0;
}
