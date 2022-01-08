#include <bits/stdc++.h>
using namespace std;
int A, B;
int main()
{
	cin >> A >> B;
	for (int i = B; i > 0; i--)
	{
		if (B / i - (A - 1) / i >= 2)
		{
			cout << i << endl;
			break;
		}
	}
}
