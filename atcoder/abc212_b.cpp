#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	if (n % 1111 == 0 || ((n % 1111 == 123 && n < 7000) || n == 7890 || n == 8901 || n == 9012))
	{
		cout << "Weak" << endl;
	}
	else
	{
		cout << "Strong" << endl;
	}
	return 0;
}
