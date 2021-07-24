#include <bits/stdc++.h>
using namespace std;
int n, a[100];
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
    int oc = 0, ec = 0;
    for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{
			++ec;
		}
	    else
	    {
			++oc;
		}
	}
    if (ec == 1) {
        for (int i = 0; i < (int)(n); ++i)
            if (a[i] % 2 == 0) cout << i + 1 << endl;
    } else {
        for (int i = 0; i < (int)(n); ++i)
            if (a[i] % 2 == 1) cout << i + 1 << endl;
    }
    return 0;
}
