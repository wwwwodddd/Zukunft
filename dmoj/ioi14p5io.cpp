#include <bits/stdc++.h>
using namespace std;
int n;
int confidence[100020];
int host[100020];
int protocol[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> confidence[i];
	}
	for (int i = 1; i < n; i++)
	{
		cin >> host[i] >> protocol[i];
	}
	int z = 0;
	for (int i = n - 1; i > 0; i--)
	{
		if (protocol[i] == 0)
		{
			z += confidence[i];
			confidence[host[i]] -= confidence[i];
			if (confidence[host[i]] < 0)
			{
				confidence[host[i]] = 0;
			}
		}
		else if (protocol[i] == 1)
		{
			confidence[host[i]] += confidence[i];
		}
		else if (protocol[i] == 2)
		{
			if (confidence[host[i]] < confidence[i])
			{
				confidence[host[i]] = confidence[i];
			}
		}
	}
	cout << confidence[0] + z << endl;
	return 0;
}