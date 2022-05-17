#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a = n / 100;
	int b = n % 100;
	if (0 < a && a < 13 && 0 < b && b < 13)
	{
		cout << "AMBIGUOUS" << endl;
	}
	else if (0 < b && b < 13)
	{
		cout << "YYMM" << endl;
	}
	else if (0 < a && a < 13)
	{
		cout << "MMYY" << endl;
	}
	else
	{
		cout << "NA" << endl;
	}
	return 0;
}
