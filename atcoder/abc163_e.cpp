#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[2020];
long long f[2020][2020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	// ��С�������η���
	for (int i = n; i > 0; i--)
	{ 
		for (int j = i; j <= n; j++)
		{
			// f[i][j] �Ѿ������� a[1] .. a[j-i+1] �� j-i+1 �����֣����õ������� [i, j] �� j-i+1 ��λ��
			// �������һ�����֣�Ҳ���� a[j-i+1] ��������� i �����ұ� j
			// ��������� i �������� ����abs(a[l].second - i) * ����a[l].first + ʣ�µ�����[i+1,j]
			// �������ұ� j �������� ����abs(a[l].second - j) * ����a[l].first + ʣ�µ�����[i,j-1]
			int l = j - i + 1;
			f[i][j] = max(abs(a[l].second - i) * a[l].first + f[i + 1][j], abs(a[l].second - j) * a[l].first + f[i][j - 1]);
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
